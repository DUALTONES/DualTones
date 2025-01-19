#pragma once
#include "../entity/entityComponents.h"

class RenderCandidate
{
public:
    TransformComponent* transformComponent;
    RenderableComponent* renderableComponent;
};