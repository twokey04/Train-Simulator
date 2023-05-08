// Copyright (C) 2019-2023, Magic Lane B.V.
// All rights reserved.
//
// This software is confidential and proprietary information of Magic Lane
// ("Confidential Information"). You shall not disclose such Confidential
// Information and shall use it only in accordance with the terms of the
// license agreement you entered into with Magic Lane.

#pragma once

#include "IMapService.h"

#include "ITextureRepository.h"
#include "IResourceRepository.h"
#include "IOpenGLContext.h"
#include "IMapServiceListener.h"

#include <API/GEM_Canvas.h>
#include <API/GEM_SdkSettings.h>

class SDKUtils;

enum class EOperation
{
    None,
    ComputeRoute,
    Navigate,
    Simulate,
    Search
};

class MagicLaneMapService : public IMapService, public gem::IOffboardListener
{
public:
    MagicLaneMapService( SDKUtils* sdkUtils );
    ~MagicLaneMapService();

    // IMapService methods implementation
    void AddListener( IMapServiceListener* listener ) override;
    void RemoveListener( IMapServiceListener* listener ) override;

    bool HasToken() const override;

    bool IsConnected() const override;
    void SetAllowConnection( bool allowConnection ) override;

    void InitGLContext( const WindowInfo& windowInfo ) override;
    IMapViewPtr GetMapView( RectF area = RectF( 0.0f, 0.0f, 1.0f, 1.0f ) ) override;
    void Resize( Size size, float pixelRatio ) override;

    ITextureRepository* GetTextureRepository() override;
    IResourceRepository* GetResourceRepository() override;

    void UpdateMaps() override;

    bool IsRenderFps() const override;
    void SetRenderFps( bool renderFps ) override;

    void Tick() override;

    // different operations
    int ComputeRoutes( gem::LandmarkList waypoints, ComputeRoutesCallback callback, ETransportMode mode = ETransportMode::Car ) override;
    void CancelComputeRoutes() override;

private:
    // gem::IOffboardListener implementation (for connection status)
    void onConnectionStatusUpdated( bool connected ) override;
    void onWorldwideRoadMapSupportDisabled( EReason reason ) override {}

    void onWorldwideRoadMapSupportStatus( EStatus state ) override;

    // some content, other than maps got updated (e.g. styles) after a CheckForUpdate call
    void onAvailableContentUpdate( int type, EStatus state ) override;

private:
    ITextureRepository* m_textureRepository;
    IResourceRepository* m_resourceRepository;

    IOpenGLContextPtr m_openGLContext;
    gem::StrongPointer<gem::Screen> m_screen;

    SDKUtils* m_sdkUtils;

    gem::SdkSettings m_settings;
    bool m_bConnected;
    bool m_bHasToken; // whether GEM_TOKEN is set (if not styles are not available, watermark present)

    std::vector<IMapServiceListener*> m_listeners;

    IMapViewPtr m_mapView;

    bool m_bRenderFps;

    EOperation m_activeOperation;

    gem::StrongPointer<gem::IProgressListener> m_operationListener;
    ComputeRoutesCallback m_computeRoutesCallback;
    gem::RouteList m_routes;
};
