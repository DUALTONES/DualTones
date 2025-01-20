#include "engineCore.h"

EngineCore::EngineCore()
{
    composer = new Composer(&messagePool, &renderQueue, activeScene);
    renderManager = new RenderManager(&renderQueue, &displayManager);
    resourceManager = new ResourceManager(&messagePool, &spriteStack, activeScene, &textureStack, &fontStack);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    resourceManager->LoadTextureToStack("TESTTEXTURE", "ehrtert");
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D);
    resourceManager->CreateSprite("TESTSPRITE", "TESTTEXTURE");
    resourceManager->AddRenderableToEntity(ENTITY_RENDERABLE::SPRITE_2D, "TESTSPRITE", "TESTSCENE", "TESTENTITY");
    resourceManager->SetActiveScene("TESTSCENE");
}

void EngineCore::Compose()
{
    composer->Update();
}

void EngineCore::Draw()
{
    renderManager->Update();
}