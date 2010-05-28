// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef XMLRPCSTREAM_INC
#define XMLRPCSTREAM_INC

#include <yarp/os/impl/InputStream.h>
#include <yarp/os/impl/OutputStream.h>
#include <yarp/os/impl/TwoWayStream.h>
#include <yarp/os/impl/StringInputStream.h>
#include <yarp/os/impl/StringOutputStream.h>

#include "XmlRpcClient.h"
#include "XmlRpcServerConnection.h"

namespace yarp {
    namespace os {
        namespace impl {
            class XmlRpcStream;
        }
    }
}

class yarp::os::impl::XmlRpcStream : public TwoWayStream, 
                                     public InputStream,
                                     public OutputStream
{
private:
    TwoWayStream *delegate;
    XmlRpc::XmlRpcClient client;
    XmlRpc::XmlRpcServerConnection server;
    StringInputStream sis;
    StringOutputStream sos;
    bool sender;
    bool firstRound;
public:
    XmlRpcStream(TwoWayStream *delegate, bool sender) : client("notset",0), 
                                                        server(0,0/*NULL*/),
                                                        sender(sender) {
        this->delegate = delegate;
        client.reset();
        server.reset();
        firstRound = true;
    }

    virtual ~XmlRpcStream() {
        if (delegate!=NULL) {
            delete delegate;
            delegate = NULL;
        }
    }

    virtual InputStream& getInputStream() { return *this; }
    virtual OutputStream& getOutputStream() { return *this; }


    virtual const Address& getLocalAddress() {
        return delegate->getLocalAddress();
    }

    virtual const Address& getRemoteAddress() {
        return delegate->getRemoteAddress();
    }

    virtual bool isOk() {
        return delegate->isOk();
    }

    virtual void reset() {
        delegate->reset();
    }

    virtual void close() {
        delegate->close();
    }

    virtual void beginPacket() {
        delegate->beginPacket();
    }

    virtual void endPacket() {
        delegate->endPacket();
    }

    virtual void write(const Bytes& b);

    virtual int read(const Bytes& b);
    //{
    //  return delegate->getInputStream().read(b);
    //}

    virtual void interrupt() { 
        delegate->getInputStream().interrupt();
    }

};

#endif
