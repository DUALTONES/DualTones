#pragma once
#include "entityComponents.h"

class Entity
{
public:
    TransformComponent* transformComponent = nullptr;
    RenderableComponent* renderableComponent = nullptr;
    RenderableAttributesComponent* renderableAttributesComponent = nullptr;
    TextAttributesComponent* textAttributesComponent = nullptr;
};