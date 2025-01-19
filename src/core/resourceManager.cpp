#include "resourceManager.h"

ResourceManager::ResourceManager(MessagePool* messagePool, SpriteStack* spriteStack, TextureStack *textureStack, FontStack *fontStack)
{
    this->messagePool = messagePool;
    this->spriteStack = spriteStack;
    this->textureStack = textureStack;
    this->fontStack = fontStack;
    fallbackTexture = LoadTexture("../assets/funnysneko/img/fallback.png");
    textureStack->AddTexture("FALLBACK", fallbackTexture);
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
    if(FileExists(path.c_str()))
    {
        font = LoadFont(path.c_str());
    }
    else
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
    messagePool->AddMessage("SCENE " + name + " IS CREATED");
}

void ResourceManager::CreateSprite(std::string name, std::string textureName)
{
    Sprite2D sprite;
    Texture2D* texture = textureStack->GetTexture(textureName);
    if(texture == nullptr)
    {
        messagePool->AddMessage("TEXTURE " + textureName + " IS NOT FOUND");
        texture = textureStack->GetTexture("FALLBACK");
    }
    sprite.SetTexture(texture);
    spriteStack->AddSprite(name, sprite);
    messagePool->AddMessage("SPRITE " + name + " IS CREATED AND USES TEXTURE " + textureName);
}

void ResourceManager::AddRenderableToEntity(ENTITY_RENDERABLE renderableType, std::string renderableName, std::string sceneName, std::string entityName)
{
    switch(renderableType)
    {
        case ENTITY_RENDERABLE::SPRITE_2D:
        {
            RenderableComponent renderableComponent(spriteStack->GetSprite(renderableName));
            scenes[sceneName].GetEntity(entityName)->AddRenderableComponent(scenes[sceneName].AddRenderableComponent(renderableName, renderableComponent));
            break;
        }
    }
}

void ResourceManager::CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform)
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

void ResourceManager::SetActiveScene(std::string name)
{
    activeScene = &scenes[name];
}
