#pragma once
#include <unordered_map>
#include <string>
#include "../entity/entity.h"

class Scene
{
public:
    void AddEntity(std::string name, Entity entity);
    Entity* GetEntity(std::string name);
    TransformComponent* AddTransform2DComponent(std::string name);
    TransformComponent* AddTransform3DComponent(std::string name);
    RenderableComponent* AddRenderableComponent(std::string name, Renderable* renderable);
    RenderableAttributesComponent* AddRenderableAttributesComponent(std::string name, Renderable2DAttributes* renderableAttributes);
    TextAttributesComponent* AddTextAttributesComponent(std::string name, TextAttributes* textAttributes);
    std::unordered_map<std::string, Entity> entities;
private:
    std::unordered_map<std::string, Transform2DComponent> transform2DComponents;
    std::unordered_map<std::string, Transform3DComponent> transform3DComponents;
    std::unordered_map<std::string, RenderableComponent> renderableComponents;
    std::unordered_map<std::string, RenderableAttributesComponent> renderableAttributesComponents;
    std::unordered_map<std::string, TextAttributesComponent> textAttributesComponents;
};