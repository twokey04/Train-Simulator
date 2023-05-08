// Copyright (C) 2019-2023, Magic Lane B.V.
// All rights reserved.
//
// This software is confidential and proprietary information of Magic Lane
// ("Confidential Information"). You shall not disclose such Confidential
// Information and shall use it only in accordance with the terms of the
// license agreement you entered into with Magic Lane.

#pragma once

enum class EMapServiceEvent
{
    Connected,
    Disconnected,
    ExpiredMaps,
    NewMaps,
    NewStyles
};

class IMapServiceListener
{
public:
    virtual void OnMapServiceEvent( EMapServiceEvent event ) = 0;

    virtual ~IMapServiceListener() = default;
};
