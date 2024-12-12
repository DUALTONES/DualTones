#include "resourceManager.h"

ResourceManager::ResourceManager()
    : preRenderManager(&sceneManager, &renderQueue)
{
    CreateDisplayManager("display", {1920, 1080}, {1000, 1000});
    CreateRenderManager("render", &renderQueue);
}

IManager *ResourceManager::GetManager(std::string &name)
{
    return managerRegistry.GetManager(name);
}

PreRenderManager *ResourceManager::GetPreRenderManager()
{
    return &preRenderManager;
}

void ResourceManager::CreateDisplayManager(std::string name, Vector2 referenceResolution, Vector2 relativeCoordinates)
{
    auto displayManager = std::make_unique<DisplayManager>(referenceResolution, relativeCoordinates);
    managerRegistry.AddManager(name, std::move(displayManager));
}

void ResourceManager::CreateRenderManager(std::string name, RenderQueue *renderQueue)
{
    auto renderManager = std::make_unique<RenderManager>(renderQueue);
    managerRegistry.AddManager(name, std::move(renderManager));
}
