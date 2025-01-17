#include "renderManager.h"

RenderManager::RenderManager()
{

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