#include "renderManager.h"

RenderManager::RenderManager(RenderQueue *renderQueue, DisplayManager *displayManager)
{
    this->renderQueue = renderQueue;
    this->displayManager = displayManager;
}

void RenderManager::Update()
{
    BeginDrawing();
    ClearBackground(BackgroundColor);

    Draw();

    EndDrawing();
}

void RenderManager::Draw()
{

}
