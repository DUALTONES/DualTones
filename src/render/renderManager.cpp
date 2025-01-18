#include "renderManager.h"

RenderManager::RenderManager(TextureStack *textureStack)
{
    this->textureStack = textureStack;
}

void RenderManager::TEMP_INIT(std::string TEMP_TEXTURE_NAME)
{
    TEMP_TEXTURE = textureStack->GetTexture(TEMP_TEXTURE_NAME);
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
    DrawTexture(*TEMP_TEXTURE, 100, 100, WHITE);
}