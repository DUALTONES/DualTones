#pragma once
#include "includes.h"
#include "managerRegistry.h"
#include "displayManager.h"
#include "preRenderManager.h"
#include "renderManager.h"

class ResourceManager
{
public:
    ResourceManager();
    IManager* GetManager(std::string& name);
    PreRenderManager* GetPreRenderManager();
private:
    void CreateDisplayManager(std::string name, Vector2 referenceResolution, Vector2 relativeCoordinats);
    void CreateRenderManager(std::string name, RenderQueue* renderQueue);
    void CreateScene();
    SceneManager sceneManager;
    PreRenderManager preRenderManager;
    RenderQueue renderQueue;
    ManagerRegistry managerRegistry;
};