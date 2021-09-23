/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/companion/impl/Companion.h>

#include <yarp/os/Bottle.h>

using yarp::companion::impl::Companion;
using yarp::os::Bottle;


namespace {
void writeBottleAsFile(const char *fileName, const Bottle& bot)
{
    FILE *fout = fopen(fileName, "w");
    if (!fout) {
        return;
    }
    for (size_t i=0; i<bot.size(); i++) {
        fprintf(fout, "%s\n", bot.get(i).toString().c_str());
    }
    fclose(fout);
    fout = nullptr;
}
} // namespace

int Companion::cmdCMake(int argc, char *argv[])
{
    YARP_UNUSED(argc);
    YARP_UNUSED(argv);
    Bottle f;
    f.addString("# Generated by \"yarp cmake\"");
    f.addString("");
    f.addString("# A cmake file to get started with for new YARP projects.");
    f.addString("# It assumes you want to build an executable from source code in ");
    f.addString("# the current directory.");
    f.addString("# Replace \"yarpy\" with whatever your executable should be called.");
    f.addString("");
    f.addString("cmake_minimum_required(VERSION 3.16)");
    f.addString("project(yarpy)");
    f.addString("");
    f.addString("# Find YARP.  Point the YARP_DIR environment variable at your build.");
    f.addString("find_package(YARP REQUIRED)");
    f.addString("");
    f.addString("# Search for source code.");
    f.addString("file(GLOB folder_source *.cpp *.cc *.c)");
    f.addString("file(GLOB folder_header *.h)");
    f.addString("");
    f.addString("# Search for IDL files.");
    f.addString("file(GLOB idl_files *.thrift *.msg *.srv)");
    f.addString("foreach(idl ${idl_files})");
    f.addString("  yarp_idl_to_dir(${idl} ${CMAKE_BINARY_DIR}/idl IDL_SRC IDL_HDR IDL_INCLUDE)");
    f.addString("  set(folder_source ${folder_source} ${IDL_SRC})");
    f.addString("  set(folder_header ${folder_header} ${IDL_HDR})");
    f.addString("  include_directories(${IDL_INCLUDE})");
    f.addString("endforeach()");
    f.addString("");
    f.addString("# Automatically add include directories if needed.");
    f.addString("foreach(header_file ${folder_header})");
    f.addString("  get_filename_component(p ${header_file} DIRECTORY)");
    f.addString("  include_directories(${p})");
    f.addString("endforeach(header_file ${folder_header})");
    f.addString("");
    f.addString("# Set up our main executable.");
    f.addString("if(folder_source)");
    f.addString("  add_executable(${PROJECT_NAME})");
    f.addString("  target_sources(${PROJECT_NAME} PRIVATE ${folder_source} ${folder_header})");
    f.addString("  target_link_libraries(${PROJECT_NAME} PRIVATE ${YARP_LIBRARIES})");
    f.addString("else()");
    f.addString("  message(FATAL_ERROR \"No source code files found. Please add something\")");
    f.addString("endif()");

    const char *target = "CMakeLists.txt";

    FILE *fin = fopen(target, "r");
    if (fin) {
        yCInfo(COMPANION, "File %s already exists, please remove it first", target);
        fclose(fin);
        fin = nullptr;
        return 1;
    }

    writeBottleAsFile(target, f);
    yCInfo(COMPANION, "Wrote to %s", target);
    yCInfo(COMPANION, "Run cmake to generate makefiles or project files for compiling.");
    return 0;
}
