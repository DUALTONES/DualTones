#pragma once
#include "entityComponents.h"

class Entity
{
public:
    Entity();
private:
    TransformComponent* transformComponent;
    RenderableComponent* renderableComponent;
};