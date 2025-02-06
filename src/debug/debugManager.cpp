#include "debugManager.h"

DebugManager::DebugManager(MessagePool *messagePool, ResourceManager* resourceManager, DisplayManager *displayManager)
{
    this->messagePool = messagePool;
    this->resourceManager = resourceManager;
    this->displayManager = displayManager;
}

void DebugManager::Update()
{
    CollectData();
    displayInfo->textAttributesComponent->textAttributes->text = "[ INFO ] RES: [" + std::to_string((int)resolution.x) + "/" + std::to_string((int)resolution.y) + "] SCALE: [" + std::to_string(scale) + "] FPS: [" + std::to_string(fps) + "]";
    Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(displayInfo->renderableComponent->renderable);
    renderable2D->CalculateDimensions();
}

void DebugManager::Init()
{
    displayInfo = resourceManager->CreateEntity("DISPLAY_INFO", "DEBUG", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    Transform2DComponent* transform2D = dynamic_cast<Transform2DComponent*>(displayInfo->transformComponent);
    transform2D->position = {0, 46};
    resourceManager->AddTextToEntity("DISPLAY_INFO", "DEBUG", "DISPLAY_INFO", "TESTFONT", 10, 0);
}

void DebugManager::CollectData()
{
    fps = GetFPS();
    resolution = displayManager->GetResolution();
    scale = displayManager->GetScale();
}