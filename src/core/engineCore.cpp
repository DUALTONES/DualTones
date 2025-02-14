#include "engineCore.h"

EngineCore::EngineCore()
{
    renderManager = new RenderManager(&messagePool, &renderQueue);
    composer = new Composer(&messagePool, &renderQueue, &displayManager, &camera2D);
    controlManager = new ControlManager(&camera2D, &inputManager);
    resourceManager = new ResourceManager(&messagePool, &renderable2DStack, &textureStack, &fontStack, composer);
    dialogueManager = new DialogueManager(&timeManager, resourceManager);
    debugManager = new DebugManager(&messagePool, resourceManager, &displayManager, &timeManager);
    TEMP_INIT();
}

void EngineCore::TEMP_INIT()
{
    displayManager.SetReferenceResolution({1280, 720});
    displayManager.SetRelativeCoordinats({100, 100});
    resourceManager->CreateScene("TESTSCENE");
    resourceManager->CreateEntity("TESTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXTURE);
    resourceManager->CreateEntity("TESTBG", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXTURE);
    resourceManager->CreateEntity("TESTTEXTENTITY", "TESTSCENE", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->LoadTextureToStack("TESTTEXTURE", "../assets/funnysneko/img/pic.png");
    resourceManager->LoadTextureToStack("TESTTEXTUREBG", "../assets/funnysneko/img/bg.png");
    resourceManager->LoadFontToStack("TESTFONT", "../assets/vendor/fonts/PressStart2P/PressStart2P-Regular.ttf");
    resourceManager->AddTextureToEntity("TESTENTITY", "TESTSCENE", "TESTTEXTURE");
    resourceManager->AddTextureToEntity("TESTBG", "TESTSCENE", "TESTTEXTUREBG");
    resourceManager->AddTextToEntity("TESTTEXTENTITY", "TESTSCENE", "DUALTONES TEST DUALTONES TEST DUALTONES TEST DUALTONES TEST DUALTONES TEST", "TESTFONT", 52, 0);
    resourceManager->SetScene("TESTSCENE");
    resourceManager->ModifyEntityDepth("TESTTEXTENTITY", "TESTSCENE", 0.9);
    resourceManager->ModifyEntityDepth("TESTBG", "TESTSCENE", 0.8);
    resourceManager->ModifyEntityDepth("TESTENTITY", "TESTSCENE", 0.3);
    resourceManager->ModifyEntityScale("TESTENTITY", "TESTSCENE", 0.9);
    //resourceManager->ModifyEntityScale("TESTBG", "TESTSCENE", 2.0);
    resourceManager->ModifyEntityPosition("TESTENTITY", "TESTSCENE", {20, 0});

    debugManager->Init();
    dialogueManager->Init();
}

void EngineCore::HandleInput()
{
    inputManager.Update();
}

void EngineCore::UpdateGameState()
{
    timeManager.Update();
    dialogueManager->Update();
    controlManager->Update();
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