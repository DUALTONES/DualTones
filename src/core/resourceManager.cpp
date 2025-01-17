#include "resourceManager.h"

ResourceManager::ResourceManager(MessagePool* messagePool, TextureStack *textureStack, FontStack *fontStack)
{
    this->messagePool = messagePool;
    this->textureStack = textureStack;
    this->fontStack = fontStack;
    fallbackTexture = LoadTexture("../assets/funnysneko/img/fallback.png");
}

void ResourceManager::LoadTextureToStack(std::string name, std::string path)
{
    Texture2D texture;

    try
    {
        texture = LoadTexture(path.c_str());
    }
    catch(const std::exception& e)
    {
        messagePool->AddMessage("FAILED TO LOAD TEXTURE " + name + " FROM " + path);
        texture = fallbackTexture;
    }

    textureStack->AddTexture(name, texture);
}

void ResourceManager::LoadFontToStack(std::string name, std::string path)
{
    Font font;

    try
    {
        font = LoadFont(path.c_str());
    }
    catch(const std::exception& e)
    {
        messagePool->AddMessage("FAILED TO LOAD FONT " + name + " FROM " + path);
        font = GetFontDefault();
    }

    fontStack->AddFont(name, font);
}