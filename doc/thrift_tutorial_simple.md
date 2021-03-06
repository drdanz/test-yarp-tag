Thrift IDL in YARP: simple tutorial                    {#thrift_tutorial_simple}
===================================

[TOC]

This tutorial shows how to use the Apache Thrift Interface Definition Language
(and relative compiler) to easily define RPC-based interfaces for YARP Modules.

Introduction                                     {#thrift_tutorial_simple_intro}
------------

Apache Thrift allows to define service interfaces in a simple definition file.
Taking that file as input, a compiler generates source code which handles the
RPC communication for commands and replies defined in the interface.
This source code can therefore be used by a server that executes the commands
and by clients that send requests to the server by means of simple function
calls.

Step One: Interface Definition              {#thrift_tutorial_simple_thriftfile}
------------------------------

Let's assume that we want to create a new module that can receive commands on a
RPC port to start/stop execution, and get/set some value. We can create a
`.thrift` text file that defines a *Thrift* service interface for our module
like this:

~~~{.thrift}
#demo.thrift
service Demo {
  i32 get_answer();
  bool set_answer(1:i32 rightAnswer)
  i32 add_one(1:i32 x);
  bool start();
  bool stop();
  bool is_running();
}
~~~

where `i32` is defined by the Thrift type system as a 32-bit signed integer,
and `bool` is a boolean value (true or false), one byte. Note that each
argument of a function is associated to a unique, positive integer identifier.
For a complete explanation of the Thrift IDL, please see \ref thrift_tutorial.

Step Two: Source code generation                               {#sec_generation}
--------------------------------

Now that we have our nice and clear interface definition, we want to generate
the source code that provides this interface in YARPic terms, and implements the
RPC communication process that occurs between a client that invokes a function
call and the server that exectutes it.

Using CMake, generation of code for our demo.thrift file can be performed
automatically during the configuration process. We create a `CMakeLists.txt`
configuration file in which we call the `yarp_idl_to_dir` macro:

~~~{.cmake}
#CMakeList.txt
cmake_minimum_required(VERSION 3.16)

#find YARP
find_package(YARP REQUIRED)

#compile definition file to generate source code into the desired directory
set(generated_libs_dir "${CMAKE_CURRENT_SOURCE_DIR}")
yarp_idl_to_dir(INPUT_FILES demo.thrift
                OUTPUT_DIR ${generated_libs_dir}
                SOURCES_VAR sources
                HEADERS_VAR headers
                INCLUDE_DIRS_VAR include_dirs)
# generated source files now listed in ${sources}
# generated header files now listed in ${headers}
# paths to include now listed in ${include_dirs}
~~~

We can now run CMake to set up an out-of-source tree build from command line:

```
$ cd <where_we_put_demo.thrift_and_CMakeLists.txt>
$ mkdir build && cd build
$ cmake -D ALLOW_IDL_GENERATION=ON ../
```

The YarpIDL macro defines a CMake "advanced" option, ALLOW_IDL_GENERATION, which
is by default set to OFF if generated code is already present in the desired
directory; we enable it with the -D ALLOW_IDL_GENERATION=ON option.
We should now see two folders, "include" and "src", appear in the source tree,
together with a demo_thrift.cmake file that helps CMake keep track of the
generated files.
Inside `include`, we find a `Demo.h` header file, which provides the interface:
~~~{.cpp}
class Demo : public yarp::os::Wire {
public:
  Demo() { yarp().setOwner(*this); }
  virtual int32_t get_answer();
  virtual bool set_answer(const int32_t rightAnswer);
  virtual int32_t add_one(const int32_t x);
  virtual bool start();
  virtual bool stop();
  virtual bool is_running();
  virtual bool read(yarp::os::ConnectionReader& connection);
};
~~~
`src` instead contains a `Demo.cpp` file that provides implementation for the
RPC communication, but there's no need to bother with it: all we need to care
about is the interface!

Step Three: Interface Implementation            {#thrift_tutorial_simple_server}
------------------------------------

It is now time to provide an implementation for the functions we defined in the
service interface. Let's create a `DemoServer.cpp` file in which:
\li we include the interface definition
~~~{.cpp}
#include <yarp/os/all.h>
#include <Demo.h>
~~~
\li we declare a derived class that overrides the methods of the interface:
~~~{.cpp}
class DemoServer : public Demo
{
  // Class members declaration
  int32_t answer;
  bool isRunning;

public:
  DemoServer();
  // function declarations, copied from Demo.h
  int32_t get_answer() override;
  bool set_answer(int32_t rightAnswer) override;
  int32_t add_one(const int32_t x) override;
  bool start() override;
  bool stop() override;
  bool is_running() override;
};
~~~

\li we provide an implementation for these methods, for example:
~~~{.cpp}
int32_t DemoServer::get_answer()
{
  std::cout << "The answer is "<< answer << std::endl;
  return answer;
}
~~~

\li finally, we need to create an istance of the DemoServer class and attach it
to a YARP port; a simple test can consist in this main() function:
~~~{.cpp}
int main(int argc, char *argv[])
{
    yarp::os::Network yarp;

    DemoServer demoServer;
    yarp::os::Port port;
    demoServer.yarp().attachAsServer(port);
    if (!port.open("/demoServer")) {
        return 1;
    }
    while (true) {
        printf("Server running happily\n");
        yarp::os::Time::delay(10);
    }
    port.close();
    return 0;
}
~~~

Client use                                      {#thrift_tutorial_simple_client}
----------

The thirft engine generates all the required code for the client. Clients can
directly invoke remote procedures on the server using a proxy object (generated
by thrift) attached to a YARP port.

Simple example:

~~~{.cpp}
#include <iostream>
#include <yarp/os/all.h>
#include <Demo.h>

int main(int argc, char *argv[])
{
  yarp::os::Property config;
  config.fromCommand(argc,argv);

  yarp::os::Network yarp;

  // This port will be used to talk to the remote server
  yarp::os::Port client_port;

  std::string servername= config.find("server").asString().c_str();
  client_port.open("/demo/client");

  // connect to server
  if (!yarp.connect("/demo/client",servername.c_str()))
  {
     std::cout << "Error! Could not connect to server " << servername << '\n';
     return -1;
  }

  // Instatate proxy object and attach it to the port -- the proxy will use this port to talk to the server
  Demo demo;
  demo.yarp().attachAsClient(client_port);

  // Now we are ready to chat with the server!
  // Notice that from now on we will invoke only the server methods declared in demo.thrift/Demo.h
  std::cout << "Hey are you up and running?\n";
  while(!demo.is_running())
  {
      std::cout << "No? Well... start!\n";
      demo.start();
  }

  std::cout << "Wonderful! I have a question for you... so, what's the answer??\n";
  int32_t answer=demo.get_answer();
  std::cout << "What?? " << answer << "?? Are you kidding??";
  answer = demo.add_one(answer);
  std::cout << " It's definitely " << answer << "!!\n";
  demo.set_answer(answer);
  std::cout << "Got it? So, repeat after me: the answer is ... " << demo.get_answer() << "! Great!\n";
  std::cout << "Ok you can relax now, I'll leave you alone\n";
  demo.stop();
  std::cout<<"Bye\n";
  return 0;
}
~~~

Implementing the server as a RFModule           {#thrift_tutorial_simple_module}
-------------------------------------

A nicer altenative is to create a YARP RFModule that also implements the service
interface:

~~~{.cpp}
class DemoServerModule : public Demo, public yarp::os::RFModule
{

  // Members declaration and service functions implementation

  // <snip> see above

  // RFModule functions declaration
  bool attach(yarp::os::Port &source);
  bool configure( yarp::os::ResourceFinder &rf );
  bool updateModule();
  bool close();
};
~~~

The RFModule implementation:


~~~{.cpp}
bool DemoServerModule::attach(yarp::os::Port &source)
{
    return this->yarp().attachAsServer(source);
}

bool DemoServerModule::configure( yarp::os::ResourceFinder &rf )
{
    std::string moduleName = rf.check("name",
            yarp::os::Value("demoServerModule"),
            "module name (string)").asString().c_str();
    setName(moduleName.c_str());

    std::string slash="/";

    attach(cmdPort);

    std::string cmdPortName= "/";
    cmdPortName+= getName();
    cmdPortName += "/cmd";
    if (!cmdPort.open(cmdPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << cmdPortName << std::endl;
        return false;
    }
    return true;
}

bool DemoServerModule::updateModule()
{
    // do something very useful

    return true;
}
bool DemoServerModule::close()
{
    cmdPort.close();
    return true;
}
~~~

And the main function:

~~~{.cpp}
// Check YARP and run the module
int main(int argc, char *argv[])
{
    yarp::os::Network yarp;
    if (!yarp.checkNetwork())
    {
        std::cout<<"Error: yarp server does not seem available"<<std::endl;
        return -1;
    }

    yarp::os::ResourceFinder rf;
    rf.configure(argc, argv);

    DemoServerModule demoMod;

    if (!demoMod.configure(rf)) {
        return -1;
    }

    return demoMod.runModule();
}
~~~


Complete example                             {#thrift_tutorial_simple_completex}
----------------

A complete example of Thrift code generation and server/client creation with
CMake is available in `example/idl/thriftSimple`

This is what we get when we launch server and client from command line (assuming
a *yarpserver* is running, and we are in the "build" directory):

<TABLE>
<TR>
<TD align="center"> \b Client </TD>
<TD align="center"> \b Server </TD>
</TR>

<TR>
<TD VALIGN="top">
```
$ ./demoClient --server /demoServerModule/cmd
yarp: Port /demo/client active at tcp://10.255.36.53:10003
```
</TD>
<TD VALIGN="top">
```
$ ./demoServerModule
||| policy set to YARP_POLICY
||| YARP_POLICY:
      <snip>
I know the answer!
yarp: Port /demoServerModule/cmd active at tcp://10.255.36.53:10002
```
</TD>
</TR>

<TR>
<TD VALIGN="top">
```
yarp: Sending output from /demo/client to /demoServerModule/cmd using tcp
Hey are you up and running?
No? Well... start!
```
</TD>
<TD VALIGN="top">
```
yarp: Receiving input from /demo/client to /demoServerModule/cmd using tcp
Indeed I am not running
Starting!
Indeed I am running
```
</TD>
</TR>

<TR>
<TD VALIGN="top">
```
Wonderful! I have a question for you... so, what's the answer??
What?? 42?? Are you kidding?? It's definitely 43!!

```
</TD>
<TD VALIGN="top">
```
The answer is 42
I'm adding one to 42. That's easy :)
OMG are you serious? The answer is 43?!?
```
</TD>
</TR>

<TR>
<TD VALIGN="top">
```
Got it? So, repeat after me: the answer is ... 43! Great!
Ok you can relax now, I'll leave you alone

```
</TD>
<TD VALIGN="top">
```
The answer is 43
Stopping!

```
</TD>
</TR>

<TR>
<TD VALIGN="top">
```
Bye
yarp: Removing output from /demo/client to /demoServerModule/cmd
```
</TD>
<TD VALIGN="top">
```
yarp: Removing input from /demo/client to /demoServerModule/cmd
```
</TD>
</TR>

</TABLE>


RPC calls can also be sent to the server from command line (note that commands
with "_" in their name can be split):

```
$ yarp rpc /demoServerModule/cmd
get_answer
Response: 42
set_answer 28
Response: [ok]
get answer
Response: 28
is running
Response: [fail]
start
Response: [ok]
is running
Response: [ok]
stop
Response: [ok]
is_running
Response: [fail]
```
