/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include "frameTransformSetMultiplexer.h"
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

using namespace yarp::sig;
using namespace yarp::dev;
using namespace yarp::os;
using namespace std;

YARP_LOG_COMPONENT(FRAMETRANSFORMSETMULTIPLEXER, "yarp.devices.FrameTransformSetMultiplexer")


/** Device driver interface */
bool FrameTransformSetMultiplexer::open(yarp::os::Searchable &config)
{
    if (!yarp::os::NetworkBase::checkNetwork()) {
        yCError(FRAMETRANSFORMSETMULTIPLEXER,"Error! YARP Network is not initialized");
        return false;
    }
    return true;
}



bool FrameTransformSetMultiplexer::detachAll()
{
    m_iFrameTransformStorageSetList.clear();
    return true;
}


bool FrameTransformSetMultiplexer::close()
{
    yCTrace(FRAMETRANSFORMSETMULTIPLEXER, "Close");
    detachAll();
    // Closing port
    return true;
}


bool FrameTransformSetMultiplexer::attachAll(const yarp::dev::PolyDriverList& devices2attach)
{
    switch (devices2attach.size())
    {
        case 2:
            // yarp tf repeater and nwc ros or ros2
        case 3:
            // yarp tf repeater, nwc ros and nwc ros2
            for (int i = 0; i < devices2attach.size(); i++)
            {
                yarp::dev::PolyDriver* polyDriverLocal = devices2attach[i]->poly;
                if (polyDriverLocal->isValid())
                {
                    yarp::dev::IFrameTransformStorageSet* iFrameTransformStorageSet=nullptr;
                    if (polyDriverLocal->view(iFrameTransformStorageSet) && iFrameTransformStorageSet!=nullptr)
                    {
                        m_iFrameTransformStorageSetList.push_back(iFrameTransformStorageSet);
                    }
                }
            }
            return true;
        default:
            yCError(FRAMETRANSFORMSETMULTIPLEXER) << "need to attach 2 or 3 devices, " << devices2attach.size() << "found";
            break;
    }
    return false;
}


bool FrameTransformSetMultiplexer::setTransforms(const std::vector<yarp::math::FrameTransform>& transforms)
{
    for (size_t i = 0; i < m_iFrameTransformStorageSetList.size(); i++)
    {
        if (m_iFrameTransformStorageSetList[i] != nullptr) {
            m_iFrameTransformStorageSetList[i]->setTransforms(transforms);
        }
        else {
            yCError(FRAMETRANSFORMSETMULTIPLEXER) << "pointer to interface IFrameTransformStorageSet not valid";
            return false;
        }
    }
    return true;
}


bool FrameTransformSetMultiplexer::setTransform(const yarp::math::FrameTransform& transform)
{
    for (size_t i = 0; i < m_iFrameTransformStorageSetList.size(); i++)
    {
        if (m_iFrameTransformStorageSetList[i] != nullptr) {
            m_iFrameTransformStorageSetList[i]->setTransform(transform);
        }
        else {
            yCError(FRAMETRANSFORMSETMULTIPLEXER) << "pointer to interface IFrameTransformStorageSet not valid";
            return false;
        }
    }
    return true;
}
