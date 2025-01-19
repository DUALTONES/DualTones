#pragma once
#include "raylib/raylib.h"
#include "renderQueue.h"
#include "displayManager.h"
#include <iostream>

class RenderManager
{
public:
    RenderManager(RenderQueue* renderQueue, DisplayManager* displayManager);
    void TEMP_INIT(std::string TEMP_TEXTURE_NAME);
    void Update();
    void Draw();
private:
    Color BackgroundColor = BLACK;
    RenderQueue* renderQueue;
    DisplayManager* displayManager;
};
