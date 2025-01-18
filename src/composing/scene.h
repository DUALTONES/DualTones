#pragma once
#include <unordered_map>
#include <string>
#include "../entity/entity.h"

class Scene
{
public:
    void AddEntity(std::string name, Entity entity);
    TransformComponent* AddTransform2DComponent(std::string name, Transform2DComponent transformComponent);
    TransformComponent* AddTransform3DComponent(std::string name, Transform3DComponent transformComponent);
private:
    std::unordered_map<std::string, Entity> entities;
    std::unordered_map<std::string, Transform2DComponent> transform2DComponents;
    std::unordered_map<std::string, Transform3DComponent> transform3DComponents;
};