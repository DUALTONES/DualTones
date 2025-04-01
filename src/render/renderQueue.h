#pragma once

#include <vector>
#include "renderCandidate.h"

class RenderQueue {
public:
    void Flush();
    void CreateRenderCandidate(Renderable2D* renderable2D, Vector2 absolutePosition, float absoluteScale);
    std::vector<RenderCandidate> queue;
};