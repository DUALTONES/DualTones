#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "resource.h"
#include "../composing/scene.h"
#include "controls/scripting/scenario.h"

static std::vector<std::string> RESOURCE_TYPE_NAMES = {
    "SCENARIO",
    "INSTRUCTION",
    "SCRIPT",
    "TEXTURE",
    "FONT",
    "COLOR",
    "SCENE",
    "ENTITY",
    "ENTITY_COMPONENT_TRANSFORM_2D",
    "ENTITY_COMPONENT_TRANSFORM_3D",
    "ENTITY_COMPONENT_RENDERABLE",
    "ENTITY_COMPONENT_TEXT_ATTRIBUTES",
    "RENDERABLE_2D",
    "TEXT_ATTRIBUTES",
};

class ResourceStack {
public:
    Resource* AddResource(std::string name, Resource* resource);
    Resource* CreateResource(std::string name, RESOURCE_TYPE resourceType);
    Resource* GetResource(std::string name, RESOURCE_TYPE resourceType);
    void RemoveResource(std::string name, RESOURCE_TYPE resourceType);
    void DisplayContent();
private:
    std::unordered_map<std::string, Resource*> stack;
};

class ResourceManager {
public:
    void Display();

    Scenario* CreateScenario(std::string name);
    Instruction* CreateInstruction(std::string name);
    Script* CreateScript(std::string name);
    Texture2D* LoadTextureToStack(std::string name, std::string path);
    Font* LoadFontToStack(std::string name, std::string path);
    Color* CreateColorOnStack(std::string name, Vector4 RGBA);
    Scene* CreateScene(std::string name);
    Entity* CreateEntity(std::string name, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable);

    Texture2D* GetTexture(std::string name);
    Font* GetFont(std::string name);
    Color* GetColor(std::string name);
    Scene* GetScene(std::string name);
    Entity* GetEntity(std::string name);

    void DeleteResource(std::string name, RESOURCE_TYPE resourceType);
    void DeleteEntity(std::string name, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable);
private:
    ResourceStack resourceStack;
};