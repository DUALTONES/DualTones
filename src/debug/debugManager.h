#pragma once
#include "../core/resourceManager.h"
#include "../controls/timeManager.h"
#include <iomanip>
#include <sstream>

class DebugManager
{
public:
    DebugManager(MessagePool* messagePool, ResourceManager* resourceManager, DisplayManager* displayManager, TimeManager* timeManager);
    void Update();
    void Init();
    void CollectData();
private:
    Vector2 resolution;
    int fps;
    float scale;
    double currentTime;
    Entity* displayInfo;
    Entity* timeInfo;
    MessagePool* messagePool;
    ResourceManager* resourceManager;
    DisplayManager* displayManager;
    TimeManager* timeManager;
};