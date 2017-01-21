﻿//--------------------------------------------------------------------------------------
// File: DirectXTK3DSceneRenderer.h
//
// This is a simple universal Windows app showing use of DirectXTK
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Common\DeviceResources.h"
#include "Common\StepTimer.h"
#include "CommonStates.h"
#include "DirectXTK\Inc\Effects.h"
#include "GeometricPrimitive.h"
#include "Model.h"
#include "PrimitiveBatch.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "VertexTypes.h"
#include "GameData.h"

#define TEXT_BUFFER_SIZE 1024

namespace Sample
{
    // This class renders a scene using DirectXTK
    class Renderer
    {
    public:
        Renderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
        void CreateDeviceDependentResources();
        void CreateWindowSizeDependentResources();
        void ReleaseDeviceDependentResources();
        void Update(DX::StepTimer const& timer);
        void Render();
        void AddTextObject();

        void RenderMenuOptions(FLOAT scale, const DirectX::FXMVECTOR& TEXT_COLOR);
        void RenderEventLog(FLOAT fGridXColumn1, FLOAT fGridY, FLOAT fTextHeight, FLOAT scale, const DirectX::FXMVECTOR& TEXT_COLOR);
        void RenderPerfCounters(FLOAT fGridXColumn1, FLOAT fGridY, FLOAT fTextHeight, FLOAT scale, const DirectX::XMVECTORF32& TEXT_COLOR);

        void RenderSocialGroupList(
            FLOAT fGridXColumn1,
            FLOAT fGridXColumn2,
            FLOAT fGridXColumn3,
            FLOAT fGridY,
            FLOAT fTextHeight,
            FLOAT scale,
            const DirectX::XMVECTORF32& TEXT_COLOR,
            std::vector<std::shared_ptr<xbox::services::social::manager::xbox_social_user_group>> nodeList
            );

    private:
        std::shared_ptr<DX::DeviceResources> m_deviceResources;

        std::unique_ptr<DirectX::CommonStates>                                  m_states;
        std::unique_ptr<DirectX::IEffectFactory>                                m_fxFactory;
        std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>  m_batch;
        std::unique_ptr<DirectX::SpriteBatch>                                   m_sprites;
        std::unique_ptr<DirectX::SpriteFont>                                    m_font;
    };
}
