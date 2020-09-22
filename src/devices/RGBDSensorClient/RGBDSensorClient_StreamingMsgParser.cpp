/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include "RGBDSensorClient_StreamingMsgParser.h"

using namespace yarp::dev;

// Callback reader for rgb
RgbImageReader_Impl::RgbImageReader_Impl() = default;
RgbImageReader_Impl::~RgbImageReader_Impl() = default;

void RgbImageReader_Impl::onRead(yarp::sig::FlexImage& datum)
{
    std::lock_guard<std::mutex> lock(mutex);
    std::swap(datum, last_rgb);
}

yarp::sig::FlexImage RgbImageReader_Impl::getImage()
{
    std::lock_guard<std::mutex> lock(mutex);
    return last_rgb;
}


// callback reader for depthImage
FloatImageReader_Impl::FloatImageReader_Impl() = default;
FloatImageReader_Impl::~FloatImageReader_Impl() = default;

void FloatImageReader_Impl::onRead(yarp::sig::ImageOf< yarp::sig::PixelFloat> & datum)
{
    std::lock_guard<std::mutex> lock(mutex);
    std::swap(datum, last_depth);
}

yarp::sig::ImageOf<yarp::sig::PixelFloat> FloatImageReader_Impl::getImage()
{
    std::lock_guard<std::mutex> lock(mutex);
    return last_depth;
}


// Streaming handler
bool RGBDSensor_StreamingMsgParser::readRgb(yarp::sig::FlexImage &data, yarp::os::Stamp *timeStamp)
{
    data = read_rgb.getImage();
    if(timeStamp) {
        port_rgb->getEnvelope(*timeStamp);
    }
    return true;
}

bool RGBDSensor_StreamingMsgParser::readDepth(yarp::sig::ImageOf< yarp::sig::PixelFloat > &data, yarp::os::Stamp *timeStamp)
{
    data = read_depth.getImage();
    if(timeStamp) {
        port_depth->getEnvelope(*timeStamp);
    }
    return true;
}

bool RGBDSensor_StreamingMsgParser::read(yarp::sig::FlexImage &rgbImage, yarp::sig::ImageOf< yarp::sig::PixelFloat > &depthImage, yarp::os::Stamp *rgbStamp, yarp::os::Stamp *depthStamp)
{
    rgbImage = read_rgb.getImage();
    depthImage = read_depth.getImage();

    if(rgbStamp) {
        port_rgb->getEnvelope(*rgbStamp);
    }

    if(depthStamp) {
        port_depth->getEnvelope(*depthStamp);
    }
    return true;
}

void RGBDSensor_StreamingMsgParser::attach(yarp::os::BufferedPort<yarp::sig::FlexImage> *_port_rgb,
            yarp::os::BufferedPort<yarp::sig::ImageOf< yarp::sig::PixelFloat> > *_port_depth)
{
    port_rgb = _port_rgb;
    port_depth = _port_depth;
    port_rgb->useCallback(read_rgb);
    port_depth->useCallback(read_depth);
}
