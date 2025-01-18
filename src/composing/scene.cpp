#include "scene.h"

void Scene::AddEntity(std::string name, Entity entity)
{
    entities.emplace(name, entity);
}

TransformComponent* Scene::AddTransform2DComponent(std::string name, Transform2DComponent transformComponent)
{
    transform2DComponents.emplace(name, transformComponent);
    return &transform2DComponents[name];
}

TransformComponent* Scene::AddTransform3DComponent(std::string name, Transform3DComponent transformComponent)
{
    transform3DComponents.emplace(name, transformComponent);
    return &transform3DComponents[name];
}