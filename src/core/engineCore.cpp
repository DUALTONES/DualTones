#include "engineCore.h"

EngineCore::EngineCore()
{
    renderManager = new RenderManager(&textureStack);
    resourceManager = new ResourceManager(&messagePool, &spriteStack, &textureStack, &fontStack);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    resourceManager->LoadTextureToStack("TESTTEXTURE", "ehrtert");
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D);
    resourceManager->CreateSprite("TESTSPRITE", "TESTTEXTURE");
    resourceManager->AddRenderableToEntity(ENTITY_RENDERABLE::SPRITE_2D, "TESTSPRITE", "TESTSCENE", "TESTENTITY");
}

void EngineCore::Draw()
{
    renderManager->Update();
}