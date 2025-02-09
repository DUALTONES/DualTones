#pragma once
#include "../composing/camera2D.h"
#include "../input/inputManager.h"
#include "raylib/raymath.h"
#include <iostream>

class ControlManager
{
public:
    ControlManager(Camera2DInternal* camera2D, InputManager* inputManager);
    void Update();
private:
    InputManager* inputManager;
    Camera2DInternal* camera2D;
};