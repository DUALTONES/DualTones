#pragma once
#include "entityComponents.h"

class Entity
{
public:
    Entity();
    void AddTransformComponent(TransformComponent* transformComponent);
    void AddRenderableComponent(RenderableComponent* renderableComponent);
private:
    TransformComponent* transformComponent;
    RenderableComponent* renderableComponent;
};