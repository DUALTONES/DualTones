#pragma once
#include "raylib/raylib.h"

class RenderManager
{
public:
    RenderManager();
    void Update();
    void Draw();
private:
    Color BackgroundColor = BLACK;
};