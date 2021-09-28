/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <MultipleAnalogSensorsMetadata.h>

#include <yarp/os/idl/WireTypes.h>

// getMetadata helper class declaration
class MultipleAnalogSensorsMetadata_getMetadata_helper :
        public yarp::os::Portable
{
public:
    MultipleAnalogSensorsMetadata_getMetadata_helper() = default;
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    SensorRPCData m_return_helper{};
};

// getMetadata helper class implementation
bool MultipleAnalogSensorsMetadata_getMetadata_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(1)) {
        return false;
    }
    if (!writer.writeTag("getMetadata", 1, 1)) {
        return false;
    }
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.read(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

// Constructor
MultipleAnalogSensorsMetadata::MultipleAnalogSensorsMetadata()
{
    yarp().setOwner(*this);
}

SensorRPCData MultipleAnalogSensorsMetadata::getMetadata()
{
    MultipleAnalogSensorsMetadata_getMetadata_helper helper{};
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", "SensorRPCData MultipleAnalogSensorsMetadata::getMetadata()");
    }
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : SensorRPCData{};
}

// help method
std::vector<std::string> MultipleAnalogSensorsMetadata::help(const std::string& functionName)
{
    bool showAll = (functionName == "--all");
    std::vector<std::string> helpString;
    if (showAll) {
        helpString.emplace_back("*** Available commands:");
        helpString.emplace_back("getMetadata");
        helpString.emplace_back("help");
    } else {
        if (functionName == "getMetadata") {
            helpString.emplace_back("SensorRPCData getMetadata() ");
            helpString.emplace_back("Read the sensor metadata necessary to configure the MultipleAnalogSensorsClient device. ");
        }
        if (functionName == "help") {
            helpString.emplace_back("std::vector<std::string> help(const std::string& functionName = \"--all\")");
            helpString.emplace_back("Return list of available commands, or help message for a specific function");
            helpString.emplace_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
            helpString.emplace_back("@return list of strings (one string per line)");
        }
    }
    if (helpString.empty()) {
        helpString.emplace_back("Command not found");
    }
    return helpString;
}

// read from ConnectionReader
bool MultipleAnalogSensorsMetadata::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        reader.fail();
        return false;
    }

    std::string tag = reader.readTag();
    bool direct = (tag == "__direct__");
    if (direct) {
        tag = reader.readTag();
    }
    while (!reader.isError()) {
        if (tag == "getMetadata") {
            MultipleAnalogSensorsMetadata_getMetadata_helper helper{};
            helper.m_return_helper = getMetadata();
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(10)) {
                    return false;
                }
                if (!writer.write(helper.m_return_helper)) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (tag == "help") {
            std::string functionName;
            if (!reader.readString(functionName)) {
                functionName = "--all";
            }
            auto help_strings = help(functionName);
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(2)) {
                    return false;
                }
                if (!writer.writeTag("many", 1, 0)) {
                    return false;
                }
                if (!writer.writeListBegin(BOTTLE_TAG_INT32, static_cast<uint32_t>(help_strings.size()))) {
                    return false;
                }
                for (const auto& help_string : help_strings) {
                    if (!writer.writeString(help_string)) {
                        return false;
                    }
                }
                if (!writer.writeListEnd()) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        std::string next_tag = reader.readTag();
        if (next_tag.empty()) {
            break;
        }
        tag.append("_").append(next_tag);
    }
    return false;
}
