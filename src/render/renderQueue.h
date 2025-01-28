#pragma once
#include <vector>
#include "renderCandidate.h"

class RenderQueue
{
public:
    void CreateRenderCandidate(Renderable* renderable, Vector2 absolutePosition, float absoluteScale);
    void Flush();
    std::vector<RenderCandidate> queue;
};