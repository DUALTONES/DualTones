#pragma once
#include "../entity/entityComponents.h"

class RenderCandidate
{
public:
    Renderable* renderable;
    Vector2 absolutePosition;
    float absoluteScale;
};