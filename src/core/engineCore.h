#pragma once
#include "../render/renderManager.h"
#include "../composing/composer.h"
#include "resourceManager.h"

class EngineCore
{
public:
    EngineCore();
    void TEMP_INIT();
    void Compose();
    void Draw();
private:
    MessagePool messagePool;
    Composer* composer;
    DisplayManager displayManager;
    RenderManager* renderManager;
    ResourceManager* resourceManager;
    Renderable2DStack renderable2DStack;
    TextureStack textureStack;
    FontStack fontStack;
    Scene* activeScene;
    RenderQueue renderQueue;
};