#include "debugManager.h"

DebugManager::DebugManager(MessagePool *messagePool, ResourceManager* resourceManager, DisplayManager *displayManager, TimeManager* timeManager)
{
    this->messagePool = messagePool;
    this->resourceManager = resourceManager;
    this->displayManager = displayManager;
    this->timeManager = timeManager;
}

void DebugManager::Update()
{
    CollectData();
    displayInfo->textAttributesComponent->textAttributes->text = "[ INFO ] RES: [" + std::to_string((int)resolution.x) + "/" + std::to_string((int)resolution.y) + "] SCALE: [" + std::to_string(scale) + "] FPS: [" + std::to_string(fps) + "]";
    Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(displayInfo->renderableComponent->renderable);
    renderable2D->CalculateDimensions();
    timeInfo->textAttributesComponent->textAttributes->text = "[ TIME INFO ] " + int(currentTime);
    renderable2D = dynamic_cast<Renderable2D*>(timeInfo->renderableComponent->renderable);
    renderable2D->CalculateDimensions();
}

void DebugManager::Init()
{
    displayInfo = resourceManager->CreateEntity("DISPLAY_INFO", "DEBUG", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->ModifyEntityPosition("DISPLAY_INFO", "DEBUG", {0, -47});
    resourceManager->ModifyEntityDepth("DISPLAY_INFO", "DEBUG", 0.95);
    resourceManager->AddTextToEntity("DISPLAY_INFO", "DEBUG", "DISPLAY_INFO", "TESTFONT", 10, 0);
    timeInfo = resourceManager->CreateEntity("TIME_INFO", "DEBUG", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->ModifyEntityPosition("TIME_INFO", "DEBUG", {0, 47});
    resourceManager->ModifyEntityDepth("TIME_INFO", "DEBUG", 0.95);
    resourceManager->AddTextToEntity("TIME_INFO", "DEBUG", "TIME_INFO", "TESTFONT", 10, 0);
}

void DebugManager::CollectData()
{
    fps = GetFPS();
    resolution = displayManager->GetResolution();
    scale = displayManager->GetScale();
    currentTime = timeManager->GetCurrentTime();
}