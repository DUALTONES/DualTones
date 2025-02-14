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
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << scale;
    displayInfo->textAttributesComponent->textAttributes->text = "[ DISPLAY INFO ] RES: [" + std::to_string((int)resolution.x) + "/" + std::to_string((int)resolution.y) + "] SCALE: [" + stream.str() + "] FPS: [" + std::to_string(fps) + "]";
    Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(displayInfo->renderableComponent->renderable);
    renderable2D->CalculateDimensions();
    std::ostringstream timeStream;
    timeStream << 
              std::setfill('0') << std::setw(2) << int(currentTime / 3600) << ":"
           << std::setfill('0') << std::setw(2) << int(currentTime / 60) << ":"
           << std::setfill('0') << std::setw(2) << (int(currentTime) % 60) << ":"
           << std::setfill('0') << std::setw(2) << static_cast<int>(std::fmod(currentTime, 1.0) * 100);

    timeInfo->textAttributesComponent->textAttributes->text = timeStream.str();
    renderable2D = dynamic_cast<Renderable2D*>(timeInfo->renderableComponent->renderable);
    renderable2D->CalculateDimensions();
}

void DebugManager::Init()
{
    displayInfo = resourceManager->CreateEntity("DISPLAY_INFO", "DEBUG", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->ModifyEntityPosition("DISPLAY_INFO", "DEBUG", {0, -47});
    resourceManager->ModifyEntityDepth("DISPLAY_INFO", "DEBUG", 0.95);
    resourceManager->AddTextToEntity("DISPLAY_INFO", "DEBUG", "DISPLAY_INFO", "TESTFONT", 10, 0, true);
    timeInfo = resourceManager->CreateEntity("TIME_INFO", "DEBUG", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->ModifyEntityPosition("TIME_INFO", "DEBUG", {0, 47});
    resourceManager->ModifyEntityDepth("TIME_INFO", "DEBUG", 0.95);
    resourceManager->AddTextToEntity("TIME_INFO", "DEBUG", "TIME_INFO", "TESTFONT", 10, 0, true);
}

void DebugManager::CollectData()
{
    fps = GetFPS();
    resolution = displayManager->GetResolution();
    scale = displayManager->GetScale();
    currentTime = timeManager->GetCurrentTime();
}