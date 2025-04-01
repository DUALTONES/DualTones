#pragma once

#include "renderable.h"

class RenderCandidate {
public:
    RenderCandidate(Renderable2D* renderable2D, Vector2 absolutePosition, float absoluteScale);
    Renderable2D* renderable2D;
    Vector2 absolutePosition;
    float absoluteScale;
};