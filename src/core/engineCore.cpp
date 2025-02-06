#include "engineCore.h"

EngineCore::EngineCore()
{
    renderManager = new RenderManager(&messagePool, &renderQueue);
    composer = new Composer(&messagePool, &renderQueue, &displayManager);
    resourceManager = new ResourceManager(&messagePool, &renderable2DStack, &textureStack, &fontStack, composer);
    debugManager = new DebugManager(&messagePool, resourceManager, &displayManager);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    displayManager.SetReferenceResolution({1280, 720});
    displayManager.SetRelativeCoordinats({100, 100});
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXTURE);
    resourceManager->CreateEntity("TESTTEXTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->LoadTextureToStack("TESTTEXTURE", "../assets/funnysneko/img/pic.png");
    resourceManager->LoadFontToStack("TESTFONT", "../assets/vendor/fonts/PressStart2P/PressStart2P-Regular.ttf");
    resourceManager->AddTextureToEntity("TESTENTITY", "TESTSCENE", "TESTTEXTURE");
    resourceManager->AddTextToEntity("TESTTEXTENTITY", "TESTSCENE", "DUALTONES TEST DUALTONES TEST DUALTONES TEST DUALTONES TEST DUALTONES TEST", "TESTFONT", 52, 0);
    resourceManager->SetScene("TESTSCENE");
    debugManager->Init();
}

void EngineCore::HandleInput()
{
    inputManager.Update();
}

void EngineCore::Compose()
{
    debugManager->Update();
    displayManager.Update();
    composer->Update();
}

void EngineCore::Draw()
{
    renderManager->Update();
}