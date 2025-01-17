#pragma once
#include "../render/renderManager.h"
#include "resourceManager.h"

class EngineCore
{
public:
    EngineCore();
    void ReadScript();
    void Compose();
    void Draw();
private:
    MessagePool messagePool;
    RenderManager renderManager;
    ResourceManager* resourceManager;
    TextureStack textureStack;
    FontStack fontStack;
    Scene* activeScene;
};