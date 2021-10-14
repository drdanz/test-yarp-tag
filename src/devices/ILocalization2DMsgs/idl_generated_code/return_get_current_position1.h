/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_CURRENT_POSITION1_H
#define YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_CURRENT_POSITION1_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <yarp/dev/Map2DLocation.h>

class return_get_current_position1 :
        public yarp::os::idl::WirePortable
{
public:
    // Fields
    bool ret{false};
    yarp::dev::Nav2D::Map2DLocation loc{};

    // Default constructor
    return_get_current_position1() = default;

    // Constructor with field values
    return_get_current_position1(const bool ret,
                                 const yarp::dev::Nav2D::Map2DLocation& loc);

    // Read structure on a Wire
    bool read(yarp::os::idl::WireReader& reader) override;

    // Read structure on a Connection
    bool read(yarp::os::ConnectionReader& connection) override;

    // Write structure on a Wire
    bool write(const yarp::os::idl::WireWriter& writer) const override;

    // Write structure on a Connection
    bool write(yarp::os::ConnectionWriter& connection) const override;

    // Convert to a printable string
    std::string toString() const;

    // If you want to serialize this class without nesting, use this helper
    typedef yarp::os::idl::Unwrapped<return_get_current_position1> unwrapped;

    class Editor :
            public yarp::os::Wire,
            public yarp::os::PortWriter
    {
    public:
        // Editor: default constructor
        Editor();

        // Editor: constructor with base class
        Editor(return_get_current_position1& obj);

        // Editor: destructor
        ~Editor() override;

        // Editor: Deleted constructors and operator=
        Editor(const Editor& rhs) = delete;
        Editor(Editor&& rhs) = delete;
        Editor& operator=(const Editor& rhs) = delete;
        Editor& operator=(Editor&& rhs) = delete;

        // Editor: edit
        bool edit(return_get_current_position1& obj, bool dirty = true);

        // Editor: validity check
        bool isValid() const;

        // Editor: state
        return_get_current_position1& state();

        // Editor: start editing
        void start_editing();

#ifndef YARP_NO_DEPRECATED // Since YARP 3.2
        YARP_DEPRECATED_MSG("Use start_editing() instead")
        void begin()
        {
            start_editing();
        }
#endif // YARP_NO_DEPRECATED

        // Editor: stop editing
        void stop_editing();

#ifndef YARP_NO_DEPRECATED // Since YARP 3.2
        YARP_DEPRECATED_MSG("Use stop_editing() instead")
        void end()
        {
            stop_editing();
        }
#endif // YARP_NO_DEPRECATED

        // Editor: ret field
        void set_ret(const bool ret);
        bool get_ret() const;
        virtual bool will_set_ret();
        virtual bool did_set_ret();

        // Editor: loc field
        void set_loc(const yarp::dev::Nav2D::Map2DLocation& loc);
        const yarp::dev::Nav2D::Map2DLocation& get_loc() const;
        virtual bool will_set_loc();
        virtual bool did_set_loc();

        // Editor: clean
        void clean();

        // Editor: read
        bool read(yarp::os::ConnectionReader& connection) override;

        // Editor: write
        bool write(yarp::os::ConnectionWriter& connection) const override;

    private:
        // Editor: state
        return_get_current_position1* obj;
        bool obj_owned;
        int group;

        // Editor: dirty variables
        bool is_dirty;
        bool is_dirty_ret;
        bool is_dirty_loc;
        int dirty_count;

        // Editor: send if possible
        void communicate();

        // Editor: mark dirty overall
        void mark_dirty();

        // Editor: mark dirty single fields
        void mark_dirty_ret();
        void mark_dirty_loc();

        // Editor: dirty_flags
        void dirty_flags(bool flag);
    };

private:
    // read/write ret field
    bool read_ret(yarp::os::idl::WireReader& reader);
    bool write_ret(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_ret(yarp::os::idl::WireReader& reader);
    bool nested_write_ret(const yarp::os::idl::WireWriter& writer) const;

    // read/write loc field
    bool read_loc(yarp::os::idl::WireReader& reader);
    bool write_loc(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_loc(yarp::os::idl::WireReader& reader);
    bool nested_write_loc(const yarp::os::idl::WireWriter& writer) const;
};

#endif // YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_CURRENT_POSITION1_H
