#include "engineCore.h"

EngineCore::EngineCore()
{
    displayManager.SetReferenceResolution({1280, 720});
    displayManager.SetRelativeCoordinats({100, 100});
    renderManager = new RenderManager(&messagePool, &renderQueue);
    composer = new Composer(&messagePool, &renderQueue, &displayManager);
    resourceManager = new ResourceManager(&messagePool, &renderable2DStack, &textureStack, &fontStack, composer);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXTURE);
    resourceManager->LoadTextureToStack("TESTTEXTURE", "wrongPath");
    resourceManager->AddTextureToEntity("TESTENTITY", "TESTSCENE", "TESTTEXTURE");
    resourceManager->SetScene("TESTSCENE");
}

void EngineCore::Compose()
{
    displayManager.Update();
    composer->Update();
}

void EngineCore::Draw()
{
    renderManager->Update();
}