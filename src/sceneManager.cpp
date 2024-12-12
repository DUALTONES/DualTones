#include "sceneManager.h"

std::vector<IObject2D> SceneManager::GetObjects()
{
    scene->GetObjects();
}

void SceneManager::SetScene(Scene* scene)
{
    this->scene = scene;
}