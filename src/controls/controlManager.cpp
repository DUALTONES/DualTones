#include "controlManager.h"

ControlManager::ControlManager(Camera2DInternal *camera2D, InputManager* inputManager)
{
    this->camera2D = camera2D;
    this->inputManager = inputManager;
}

void ControlManager::Update()
{
    camera2D->position = Vector2Scale(inputManager->mousePosition, 0.01);
}