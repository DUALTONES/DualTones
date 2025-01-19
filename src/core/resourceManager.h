#pragma once
#include "resources.h"
#include "../debug/messagePool.h"
#include "../composing/scene.h"

enum class ENTITY_TRANSFORM
{
    TRANSFORM_2D,
    TRANSFORM_3D,
    NONE
};

enum class ENTITY_RENDERABLE
{
    SPRITE_2D,
    TEXT_2D
};

class ResourceManager
{
public:
    ResourceManager(MessagePool* messagePool, SpriteStack* spriteStack, TextureStack* textureStack, FontStack* fontStack);
    void LoadTextureToStack(std::string name, std::string path);
    void LoadFontToStack(std::string name, std::string path);
    void CreateScene(std::string name);
    void CreateSprite(std::string name, std::string textureName);
    void AddRenderableToEntity(ENTITY_RENDERABLE renderableType, std::string renderableName, std::string sceneName, std::string entityName);
    void CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform);
    Scene* GetScene(std::string name);
    void SetActiveScene(std::string name);
private:
    MessagePool* messagePool;
    TextureStack* textureStack;
    FontStack* fontStack;
    Texture2D fallbackTexture;
    Scene* activeScene;
    SpriteStack* spriteStack;
    std::unordered_map<std::string, Scene> scenes;
};