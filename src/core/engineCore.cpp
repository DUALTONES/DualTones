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
    //resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXTURE);
    resourceManager->CreateEntity("TESTTEXTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->LoadTextureToStack("TESTTEXTURE", "wrongPath");
    resourceManager->LoadFontToStack("TESTFONT", "../assets/vendor/fonts/PressStart2P/PressStart2P-Regular.ttf");
    //resourceManager->AddTextureToEntity("TESTENTITY", "TESTSCENE", "TESTTEXTURE");
    resourceManager->AddTextToEntity("TESTTEXTENTITY", "TESTSCENE", "TEXT IS NOW SUPPORTED", "TESTFONT", 12, 0);
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