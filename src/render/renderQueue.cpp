#include "renderQueue.h"

void RenderQueue::Flush() {
    queue.clear();
}

void RenderQueue::CreateRenderCandidate(Renderable2D *renderable2D, Vector2 absolutePosition, float absoluteScale) {
    RenderCandidate renderCandidate(renderable2D, absolutePosition, absoluteScale);
    queue.push_back(renderCandidate);
}