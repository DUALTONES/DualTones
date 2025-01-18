#include "renderManager.h"

RenderManager::RenderManager(TextureStack *textureStack)
{
    this->textureStack = textureStack;
}

void RenderManager::TEMP_INIT(std::string TEMP_TEXTURE_NAME)
{
    TEMP_TEXTURE = textureStack->GetTexture(TEMP_TEXTURE_NAME);
    if(TEMP_TEXTURE == nullptr)
    {
        std::cout << "YOU ARE A FUCKING DUMBASS" << std::endl;
    }
    else
    {
        std::cout << "NO WAY IT WORKS" << std::endl;
    }
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
    DrawTexture(TEMP_TEXTURE, 100, 100, WHITE);
}