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
    TEXT_2D,
    NONE
    //TO BE EXTENDED
};

class ResourceManager
{
public:
    ResourceManager(MessagePool* messagePool, TextureStack* textureStack, FontStack* fontStack);
    void LoadTextureToStack(std::string name, std::string path);
    void LoadFontToStack(std::string name, std::string path);
    void CreateScene();
    void CreateEntity(ENTITY_TRANSFORM entityTransform, ENTITY_RENDERABLE entityRenderable);
private:
    MessagePool* messagePool;
    TextureStack* textureStack;
    FontStack* fontStack;
    Texture2D fallbackTexture;
};