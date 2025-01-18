#include "renderManager.h"

RenderManager::RenderManager(TextureStack *textureStack)
{
    this->textureStack = textureStack;
}

void RenderManager::TEMP_INIT(std::string TEMP_TEXTURE_NAME)
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