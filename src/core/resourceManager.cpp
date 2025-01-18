#include "resourceManager.h"
#include <iostream>

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
    if(FileExists(path.c_str()))
    {
        texture = LoadTexture(path.c_str());
    }
    else
    {
        texture = fallbackTexture;
        messagePool->AddMessage("FAILED TO LOAD TEXTURE " + name + " FROM " + path);
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

void ResourceManager::CreateScene(std::string name)
{
    Scene scene;
    scenes.emplace(name, scene);
}

void ResourceManager::CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform, ENTITY_RENDERABLE entityRenderable)
{
    Scene* scene = GetScene(sceneName);
    Entity entity;
    switch(entityTransform)
    {
        case ENTITY_TRANSFORM::TRANSFORM_2D:
        {
            Transform2DComponent transformComponent;
            entity.AddTransformComponent(scene->AddTransform2DComponent(name, transformComponent));
            break;
        }
        case ENTITY_TRANSFORM::TRANSFORM_3D:
        {
            Transform3DComponent transformComponent;
            entity.AddTransformComponent(scene->AddTransform3DComponent(name, transformComponent));
            break;
        }
    }
    messagePool->AddMessage("ADDED ENTITY " + name + " TO THE SCENE " + sceneName);
}

Scene *ResourceManager::GetScene(std::string name)
{
    return &scenes[name];
}