/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_all_paths.h>

// Constructor with field values
return_get_all_paths::return_get_all_paths(const bool retval,
                                           const std::vector<yarp::dev::Nav2D::Map2DPath>& paths) :
        WirePortable(),
        retval(retval),
        paths(paths)
{
}

// Read structure on a Wire
bool return_get_all_paths::read(yarp::os::idl::WireReader& reader)
{
    if (!read_retval(reader)) {
        return false;
    }
    if (!read_paths(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool return_get_all_paths::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool return_get_all_paths::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_retval(writer)) {
        return false;
    }
    if (!write_paths(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool return_get_all_paths::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string return_get_all_paths::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// read retval field
bool return_get_all_paths::read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = false;
    }
    return true;
}

// write retval field
bool return_get_all_paths::write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read (nested) retval field
bool return_get_all_paths::nested_read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = false;
    }
    return true;
}

// write (nested) retval field
bool return_get_all_paths::nested_write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read paths field
bool return_get_all_paths::read_paths(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    paths.clear();
    uint32_t _size;
    yarp::os::idl::WireState _etype;
    reader.readListBegin(_etype, _size);
    paths.resize(_size);
    for (size_t _i = 0; _i < _size; ++_i) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readNested(paths[_i])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write paths field
bool return_get_all_paths::write_paths(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(paths.size()))) {
        return false;
    }
    for (const auto& _item : paths) {
        if (!writer.writeNested(_item)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read (nested) paths field
bool return_get_all_paths::nested_read_paths(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    paths.clear();
    uint32_t _size;
    yarp::os::idl::WireState _etype;
    reader.readListBegin(_etype, _size);
    paths.resize(_size);
    for (size_t _i = 0; _i < _size; ++_i) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readNested(paths[_i])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write (nested) paths field
bool return_get_all_paths::nested_write_paths(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(paths.size()))) {
        return false;
    }
    for (const auto& _item : paths) {
        if (!writer.writeNested(_item)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}