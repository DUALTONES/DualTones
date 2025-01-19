#include "scene.h"

void Scene::AddEntity(std::string name, Entity entity)
{
    entities.emplace(name, entity);
}

Entity *Scene::GetEntity(std::string name)
{
    return &entities[name];
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

RenderableComponent *Scene::AddRenderableComponent(std::string name, RenderableComponent renderableComponent)
{
    renderableComponents.emplace(name, renderableComponent);
    return &renderableComponents[name];
}
