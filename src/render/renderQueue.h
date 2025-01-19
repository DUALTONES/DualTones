#pragma once
#include <vector>
#include "renderCandidate.h"

class RenderQueue
{
public:
    void Flush();
    void AddRenderCandidate(TransformComponent* transformComponent, RenderableComponent* renderableComponent);
    std::vector<RenderCandidate> queue;
};