#include "scene.h"

Scene::~Scene()
{
    objects.clear();
}

void Scene::AddObject(IObject2D object)
{
    objects.push_back(object);
}

std::vector<IObject2D> Scene::GetObjects()
{
    return objects;
}