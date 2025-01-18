#pragma once
#include "raylib/raylib.h"
#include "../core/resources.h"
#include <iostream>

class RenderManager
{
public:
    RenderManager(TextureStack* textureStack);
    void TEMP_INIT(std::string TEMP_TEXTURE_NAME);
    void Update();
    void Draw();
private:
    Color BackgroundColor = BLACK;
    Texture2D* TEMP_TEXTURE;
    TextureStack* textureStack;
};