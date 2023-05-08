// Copyright (C) 2019-2023, Magic Lane B.V.
// All rights reserved.
//
// This software is confidential and proprietary information of Magic Lane
// ("Confidential Information"). You shall not disclose such Confidential
// Information and shall use it only in accordance with the terms of the
// license agreement you entered into with Magic Lane.

#pragma once

#include "ApiCallLoggerImpl.h"
#include "TimerServiceImpl.h"

#include "API/GEM_Types.h"

class SDKUtils
{
public:
    ~SDKUtils();

    int InitSDK( std::string logFile = std::string() );

    void Tick();

    void ReleaseSDK();

private:
    gem::StrongPointer<ApiCallLoggerImpl> apiLogger;
    gem::StrongPointer<TimerServiceImpl> apiTimer;
};

