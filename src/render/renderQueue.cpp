#include "renderQueue.h"

void RenderQueue::Flush()
{
    queue.clear();
}

void RenderQueue::AddRenderCandidate(TransformComponent *transformComponent, RenderableComponent *renderableComponent)
{
    RenderCandidate renderCandidate;
    renderCandidate.transformComponent = transformComponent;
    renderCandidate.renderableComponent = renderableComponent;
}