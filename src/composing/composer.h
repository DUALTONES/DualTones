#pragma once

#include "displayManager.h"
#include "scene.h"
#include "camera2D.h"
#include "../render/renderQueue.h"

class Composer {
public:
    Composer(RenderQueue* renderQueue, DisplayManager* displayManager, Camera2DInternal* camera2D);
    void Update();
private:
    RenderQueue* renderQueue;
    DisplayManager* displayManager;
    std::vector<Scene*> scenes;
    Camera2DInternal* camera2D;
};