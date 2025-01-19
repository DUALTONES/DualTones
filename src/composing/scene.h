#pragma once
#include <unordered_map>
#include <string>
#include "../entity/entity.h"

class Scene
{
public:
    void AddEntity(std::string name, Entity entity);
    Entity* GetEntity(std::string name);
    TransformComponent* AddTransform2DComponent(std::string name, Transform2DComponent transformComponent);
    TransformComponent* AddTransform3DComponent(std::string name, Transform3DComponent transformComponent);
    RenderableComponent* AddRenderableComponent(std::string name, RenderableComponent renderableComponent);
    std::unordered_map<std::string, Entity> entities;
private:
    std::unordered_map<std::string, Transform2DComponent> transform2DComponents;
    std::unordered_map<std::string, Transform3DComponent> transform3DComponents;
    std::unordered_map<std::string, RenderableComponent> renderableComponents;
};