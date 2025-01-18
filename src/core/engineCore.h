#pragma once
#include "../render/renderManager.h"
#include "resourceManager.h"

class EngineCore
{
public:
    EngineCore();
    void TEMP_INIT();
    void Draw();
private:
    MessagePool messagePool;
    RenderManager* renderManager;
    ResourceManager* resourceManager;
    TextureStack textureStack;
    FontStack fontStack;
    Scene* activeScene;
};