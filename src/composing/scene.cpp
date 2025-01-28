#include "scene.h"

void Scene::AddEntity(std::string name, Entity entity)
{
    entities.emplace(name, entity);
}

Entity *Scene::GetEntity(std::string name)
{
    if(entities.find(name) == entities.end())
    {
        return nullptr;
    }
    return &entities[name];
}

TransformComponent* Scene::AddTransform2DComponent(std::string name)
{
    Transform2DComponent transformComponent;
    transform2DComponents.emplace(name, transformComponent);
    return &transform2DComponents[name];
}

TransformComponent* Scene::AddTransform3DComponent(std::string name)
{
    Transform3DComponent transformComponent;
    transform3DComponents.emplace(name, transformComponent);
    return &transform3DComponents[name];
}

RenderableComponent *Scene::AddRenderableComponent(std::string name, Renderable* renderable)
{
    RenderableComponent renderableComponent;
    renderableComponent.renderable = renderable;
    renderableComponents.emplace(name, renderableComponent);
    return &renderableComponents[name];
}

RenderableAttributesComponent *Scene::AddRenderableAttributesComponent(std::string name, Renderable2DAttributes* renderableAttributes)
{
    RenderableAttributesComponent renderableAttributesComponent;
    renderableAttributesComponent.renderableAttributes = renderableAttributes;
    renderableAttributesComponents.emplace(name, renderableAttributesComponent);
    return &renderableAttributesComponents[name];
}

TextAttributesComponent *Scene::AddTextAttributesComponent(std::string name, TextAttributes *textAttributes)
{
    TextAttributesComponent textAttributesComponent;
    textAttributesComponent.textAttributes = textAttributes;
    textAttributesComponents.emplace(name, textAttributesComponent);
    return &textAttributesComponents[name];
}