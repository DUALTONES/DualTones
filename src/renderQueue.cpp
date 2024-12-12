#include "renderQueue.h"

std::vector<RenderCandidate*> RenderQueue::GetCandidates()
{
    return queue;
}

void RenderQueue::AddCandidate(RenderCandidate* candidate)
{
    queue.push_back(candidate);
}
