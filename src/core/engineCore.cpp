#include "engineCore.h"

EngineCore::EngineCore()
{
    renderManager = new RenderManager(&textureStack);
    resourceManager = new ResourceManager(&messagePool, &textureStack, &fontStack);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    resourceManager->LoadTextureToStack("TESTTEXTURE", "wegwegwegwegweg");
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, ENTITY_RENDERABLE::SPRITE_2D);
    renderManager->TEMP_INIT("TESTTEXTURE");
}

void EngineCore::Draw()
{
    renderManager->Update();
}