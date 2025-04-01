#pragma once

#include "../core/resourceManager.h"

class SceneManager {
public:
    void CreateScene(std::string name);
    void CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable);
private:
    std::unordered_map<std::string, Scene*> scenes;
    ResourceManager* resourceManager;
};