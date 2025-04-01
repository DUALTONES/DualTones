#include "sceneManager.h"

void SceneManager::CreateScene(std::string name) {
    Scene* scene = resourceManager->CreateScene(name);
    scenes[name] = scene;
}

void SceneManager::CreateEntity(std::string name,  std::string sceneName, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable) {
    Entity* entity = resourceManager->CreateEntity(name, entityTransform, entityRenderable);
    Scene* scene = scenes[sceneName];
    scene->entities.push_back(entity);
}