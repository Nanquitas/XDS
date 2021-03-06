// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.


#include "citraimport/GPU/video_core/pica.h"
#include "citraimport/GPU/video_core/renderer_base.h"
#include "citraimport/GPU/video_core/video_core.h"
#include "citraimport/GPU/video_core/renderer_opengl/renderer_opengl.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Video Core namespace

namespace VideoCore {

EmuWindow*      g_emu_window    = nullptr;     ///< Frontend emulator window
RendererBase*   g_renderer      = nullptr;     ///< Renderer plugin

std::atomic<bool> g_hw_renderer_enabled;
std::atomic<bool> g_shader_jit_enabled;

/// Initialize the video core
void Init(EmuWindow* emu_window) {
    Pica::Init();

    g_emu_window = emu_window;
    g_renderer = new RendererOpenGL();
    g_renderer->SetWindow(g_emu_window);
    g_renderer->Init();

    LOG_DEBUG(Render, "initialized OK");
}

/// Shutdown the video core
void Shutdown() {
    Pica::Shutdown();

    delete g_renderer;

    LOG_DEBUG(Render, "shutdown OK");
}

} // namespace
