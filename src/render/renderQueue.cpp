#include "renderQueue.h"

void RenderQueue::CreateRenderCandidate(Renderable *renderable, Vector2 absolutePosition, float absoluteScale)
{
    RenderCandidate renderCandidate;
    renderCandidate.renderable = renderable;
    renderCandidate.absolutePosition = absolutePosition;
    renderCandidate.absoluteScale = absoluteScale;
    queue.push_back(renderCandidate);
}

void RenderQueue::Flush()
{
    queue.clear();
}