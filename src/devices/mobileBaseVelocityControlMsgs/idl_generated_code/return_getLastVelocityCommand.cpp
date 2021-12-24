/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_getLastVelocityCommand.h>

// Constructor with field values
return_getLastVelocityCommand::return_getLastVelocityCommand(const bool retvalue,
                                                             const double x_vel,
                                                             const double y_vel,
                                                             const double theta_vel) :
        WirePortable(),
        retvalue(retvalue),
        x_vel(x_vel),
        y_vel(y_vel),
        theta_vel(theta_vel)
{
}

// Read structure on a Wire
bool return_getLastVelocityCommand::read(yarp::os::idl::WireReader& reader)
{
    if (!read_retvalue(reader)) {
        return false;
    }
    if (!read_x_vel(reader)) {
        return false;
    }
    if (!read_y_vel(reader)) {
        return false;
    }
    if (!read_theta_vel(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool return_getLastVelocityCommand::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(4)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool return_getLastVelocityCommand::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_retvalue(writer)) {
        return false;
    }
    if (!write_x_vel(writer)) {
        return false;
    }
    if (!write_y_vel(writer)) {
        return false;
    }
    if (!write_theta_vel(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool return_getLastVelocityCommand::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(4)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string return_getLastVelocityCommand::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// read retvalue field
bool return_getLastVelocityCommand::read_retvalue(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readBool(retvalue)) {
        reader.fail();
        return false;
    }
    return true;
}

// write retvalue field
bool return_getLastVelocityCommand::write_retvalue(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retvalue)) {
        return false;
    }
    return true;
}

// read (nested) retvalue field
bool return_getLastVelocityCommand::nested_read_retvalue(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readBool(retvalue)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) retvalue field
bool return_getLastVelocityCommand::nested_write_retvalue(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retvalue)) {
        return false;
    }
    return true;
}

// read x_vel field
bool return_getLastVelocityCommand::read_x_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(x_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write x_vel field
bool return_getLastVelocityCommand::write_x_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(x_vel)) {
        return false;
    }
    return true;
}

// read (nested) x_vel field
bool return_getLastVelocityCommand::nested_read_x_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(x_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) x_vel field
bool return_getLastVelocityCommand::nested_write_x_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(x_vel)) {
        return false;
    }
    return true;
}

// read y_vel field
bool return_getLastVelocityCommand::read_y_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(y_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write y_vel field
bool return_getLastVelocityCommand::write_y_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(y_vel)) {
        return false;
    }
    return true;
}

// read (nested) y_vel field
bool return_getLastVelocityCommand::nested_read_y_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(y_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) y_vel field
bool return_getLastVelocityCommand::nested_write_y_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(y_vel)) {
        return false;
    }
    return true;
}

// read theta_vel field
bool return_getLastVelocityCommand::read_theta_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(theta_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write theta_vel field
bool return_getLastVelocityCommand::write_theta_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(theta_vel)) {
        return false;
    }
    return true;
}

// read (nested) theta_vel field
bool return_getLastVelocityCommand::nested_read_theta_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(theta_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) theta_vel field
bool return_getLastVelocityCommand::nested_write_theta_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(theta_vel)) {
        return false;
    }
    return true;
}