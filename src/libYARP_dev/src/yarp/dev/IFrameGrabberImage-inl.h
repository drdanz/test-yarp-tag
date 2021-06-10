/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_DEV_IFRAMEGRABBERIMAGE_INL_H
#define YARP_DEV_IFRAMEGRABBERIMAGE_INL_H

#include <yarp/sig/ImageUtils.h>
#include <yarp/os/LogComponent.h>

YARP_DECLARE_LOG_COMPONENT(IFRAMEGRABBEROF)

namespace yarp {
namespace dev {

template <typename ImageType>
bool IFrameGrabberOf<ImageType>::getImageCrop(cropType_id_t cropType,
                                              yarp::sig::VectorOf<std::pair<int, int>> vertices,
                                              ImageType& image)
{
    if (cropType == YARP_CROP_RECT) {
        if (vertices.size() != 2) {
            yCError(IFRAMEGRABBEROF, "GetImageCrop failed: RECT mode requires 2 vertices");
            return false;
        }
        ImageType full;
        getImage(full);

        if (!yarp::sig::utils::cropRect(full, vertices[0], vertices[1], image)) {
            yCError(IFRAMEGRABBEROF, "GetImageCrop failed: utils::cropRect error");
            return false;
        }
    } else if(cropType == YARP_CROP_LIST) {
        yCError(IFRAMEGRABBEROF, "List type not yet implemented");
        return false;
    }

    return true;
}

} // namespace dev
} // namespace yarp

#endif // YARP_DEV_IFRAMEGRABBERIMAGE_INL_H