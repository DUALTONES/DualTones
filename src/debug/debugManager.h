#pragma once
#include "../core/resourceManager.h"
#

class DebugManager
{
public:
    DebugManager(MessagePool* messagePool, ResourceManager* resourceManager, DisplayManager* displayManager);
    void Update();
    void Init();
    void CollectData();
private:
    Vector2 resolution;
    int fps;
    float scale;
    Entity* displayInfo;
    MessagePool* messagePool;
    ResourceManager* resourceManager;
    DisplayManager* displayManager;
};