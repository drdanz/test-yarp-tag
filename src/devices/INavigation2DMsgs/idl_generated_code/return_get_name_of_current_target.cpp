/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_name_of_current_target.h>

// Constructor with field values
return_get_name_of_current_target::return_get_name_of_current_target(const bool ret,
                                                                     const std::string& name) :
        WirePortable(),
        ret(ret),
        name(name)
{
}

// Read structure on a Wire
bool return_get_name_of_current_target::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!read_name(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool return_get_name_of_current_target::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool return_get_name_of_current_target::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!write_name(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool return_get_name_of_current_target::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string return_get_name_of_current_target::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// Editor: default constructor
return_get_name_of_current_target::Editor::Editor()
{
    group = 0;
    obj_owned = true;
    obj = new return_get_name_of_current_target;
    dirty_flags(false);
    yarp().setOwner(*this);
}

// Editor: constructor with base class
return_get_name_of_current_target::Editor::Editor(return_get_name_of_current_target& obj)
{
    group = 0;
    obj_owned = false;
    edit(obj, false);
    yarp().setOwner(*this);
}

// Editor: destructor
return_get_name_of_current_target::Editor::~Editor()
{
    if (obj_owned) {
        delete obj;
    }
}

// Editor: edit
bool return_get_name_of_current_target::Editor::edit(return_get_name_of_current_target& obj, bool dirty)
{
    if (obj_owned) {
        delete this->obj;
    }
    this->obj = &obj;
    obj_owned = false;
    dirty_flags(dirty);
    return true;
}

// Editor: validity check
bool return_get_name_of_current_target::Editor::isValid() const
{
    return obj != nullptr;
}

// Editor: state
return_get_name_of_current_target& return_get_name_of_current_target::Editor::state()
{
    return *obj;
}

// Editor: grouping begin
void return_get_name_of_current_target::Editor::start_editing()
{
    group++;
}

// Editor: grouping end
void return_get_name_of_current_target::Editor::stop_editing()
{
    group--;
    if (group == 0 && is_dirty) {
        communicate();
    }
}
// Editor: ret setter
void return_get_name_of_current_target::Editor::set_ret(const bool ret)
{
    will_set_ret();
    obj->ret = ret;
    mark_dirty_ret();
    communicate();
    did_set_ret();
}

// Editor: ret getter
bool return_get_name_of_current_target::Editor::get_ret() const
{
    return obj->ret;
}

// Editor: ret will_set
bool return_get_name_of_current_target::Editor::will_set_ret()
{
    return true;
}

// Editor: ret did_set
bool return_get_name_of_current_target::Editor::did_set_ret()
{
    return true;
}

// Editor: name setter
void return_get_name_of_current_target::Editor::set_name(const std::string& name)
{
    will_set_name();
    obj->name = name;
    mark_dirty_name();
    communicate();
    did_set_name();
}

// Editor: name getter
const std::string& return_get_name_of_current_target::Editor::get_name() const
{
    return obj->name;
}

// Editor: name will_set
bool return_get_name_of_current_target::Editor::will_set_name()
{
    return true;
}

// Editor: name did_set
bool return_get_name_of_current_target::Editor::did_set_name()
{
    return true;
}

// Editor: clean
void return_get_name_of_current_target::Editor::clean()
{
    dirty_flags(false);
}

// Editor: read
bool return_get_name_of_current_target::Editor::read(yarp::os::ConnectionReader& connection)
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        return false;
    }
    int len = reader.getLength();
    if (len == 0) {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(1)) {
            return false;
        }
        writer.writeString("send: 'help' or 'patch (param1 val1) (param2 val2)'");
        return true;
    }
    std::string tag;
    if (!reader.readString(tag)) {
        return false;
    }
    if (tag == "help") {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(2)) {
            return false;
        }
        if (!writer.writeTag("many", 1, 0)) {
            return false;
        }
        if (reader.getLength() > 0) {
            std::string field;
            if (!reader.readString(field)) {
                return false;
            }
            if (field == "ret") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("bool ret")) {
                    return false;
                }
            }
            if (field == "name") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::string name")) {
                    return false;
                }
            }
        }
        if (!writer.writeListHeader(3)) {
            return false;
        }
        writer.writeString("*** Available fields:");
        writer.writeString("ret");
        writer.writeString("name");
        return true;
    }
    bool nested = true;
    bool have_act = false;
    if (tag != "patch") {
        if (((len - 1) % 2) != 0) {
            return false;
        }
        len = 1 + ((len - 1) / 2);
        nested = false;
        have_act = true;
    }
    for (int i = 1; i < len; ++i) {
        if (nested && !reader.readListHeader(3)) {
            return false;
        }
        std::string act;
        std::string key;
        if (have_act) {
            act = tag;
        } else if (!reader.readString(act)) {
            return false;
        }
        if (!reader.readString(key)) {
            return false;
        }
        if (key == "ret") {
            will_set_ret();
            if (!obj->nested_read_ret(reader)) {
                return false;
            }
            did_set_ret();
        } else if (key == "name") {
            will_set_name();
            if (!obj->nested_read_name(reader)) {
                return false;
            }
            did_set_name();
        } else {
            // would be useful to have a fallback here
        }
    }
    reader.accept();
    yarp::os::idl::WireWriter writer(reader);
    if (writer.isNull()) {
        return true;
    }
    writer.writeListHeader(1);
    writer.writeVocab32('o', 'k');
    return true;
}

// Editor: write
bool return_get_name_of_current_target::Editor::write(yarp::os::ConnectionWriter& connection) const
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(dirty_count + 1)) {
        return false;
    }
    if (!writer.writeString("patch")) {
        return false;
    }
    if (is_dirty_ret) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("ret")) {
            return false;
        }
        if (!obj->nested_write_ret(writer)) {
            return false;
        }
    }
    if (is_dirty_name) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("name")) {
            return false;
        }
        if (!obj->nested_write_name(writer)) {
            return false;
        }
    }
    return !writer.isError();
}

// Editor: send if possible
void return_get_name_of_current_target::Editor::communicate()
{
    if (group != 0) {
        return;
    }
    if (yarp().canWrite()) {
        yarp().write(*this);
        clean();
    }
}

// Editor: mark dirty overall
void return_get_name_of_current_target::Editor::mark_dirty()
{
    is_dirty = true;
}

// Editor: ret mark_dirty
void return_get_name_of_current_target::Editor::mark_dirty_ret()
{
    if (is_dirty_ret) {
        return;
    }
    dirty_count++;
    is_dirty_ret = true;
    mark_dirty();
}

// Editor: name mark_dirty
void return_get_name_of_current_target::Editor::mark_dirty_name()
{
    if (is_dirty_name) {
        return;
    }
    dirty_count++;
    is_dirty_name = true;
    mark_dirty();
}

// Editor: dirty_flags
void return_get_name_of_current_target::Editor::dirty_flags(bool flag)
{
    is_dirty = flag;
    is_dirty_ret = flag;
    is_dirty_name = flag;
    dirty_count = flag ? 2 : 0;
}

// read ret field
bool return_get_name_of_current_target::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_name_of_current_target::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_name_of_current_target::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_name_of_current_target::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read name field
bool return_get_name_of_current_target::read_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write name field
bool return_get_name_of_current_target::write_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(name)) {
        return false;
    }
    return true;
}

// read (nested) name field
bool return_get_name_of_current_target::nested_read_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) name field
bool return_get_name_of_current_target::nested_write_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(name)) {
        return false;
    }
    return true;
}
