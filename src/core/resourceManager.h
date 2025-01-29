#pragma once
#include "resources.h"
#include "../debug/messagePool.h"
#include "../composing/composer.h"

class ResourceManager
{
public:
    ResourceManager(MessagePool* messagePool, Renderable2DStack* renderable2DStack, TextureStack* textureStack, FontStack* fontStack, Composer* composer);
    void LoadTextureToStack(std::string name, std::string path);
    void LoadFontToStack(std::string name, std::string path);
    void CreateScene(std::string name);
    void CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE renderableType, PIVOT_POINT_2D pivotPoint = PIVOT_POINT_2D::CENTER);
    void AddTextToEntity(std::string name, std::string sceneName, std::string text, std::string fontName, float fontSize, float spacing);
    void AddTextureToEntity(std::string name, std::string sceneName, std::string textureName);
    Renderable2D* CreateRenderable2D(std::string name, RENDERABLE_TYPE renderableType);
    void SetScene(std::string name);
    Scene* GetScene(std::string name);
private:
    Composer* composer;
    MessagePool* messagePool;
    TextureStack* textureStack;
    FontStack* fontStack;
    Texture2D fallbackTexture;
    Renderable2DStack* renderable2DStack;
    std::unordered_map<std::string, Scene> scenes;
};