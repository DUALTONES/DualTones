#pragma once
#include "scene.h"
#include "../render/renderQueue.h"
#include "../debug/messagePool.h"
#include "displayManager.h"
#include "camera2D.h"
#include <vector>

class Composer
{
public:
    Composer(MessagePool* messagePool, RenderQueue* renderQueue, DisplayManager* displayManager);
    void Update();
    void SetScenes(std::vector<Scene*> scenes);
private:
    DisplayManager* displayManager;
    RenderQueue* renderQueue;
    MessagePool* messagePool;
    Camera2DInternal* Camera2DInternal;
    std::vector<Scene*> scenes;
};