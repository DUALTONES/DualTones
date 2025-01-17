#include "engineCore.h"

EngineCore::EngineCore()
{
    resourceManager = new ResourceManager(&messagePool, &textureStack, &fontStack);
}

void EngineCore::Draw()
{
    renderManager.Update();
}