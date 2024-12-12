#pragma once
#include "includes.h"
#include "renderCandidate.h"

class RenderQueue
{
public:
    std::vector<RenderCandidate*> GetCandidates();
    void AddCandidate(RenderCandidate* candidate);
private:
    std::vector<RenderCandidate*> queue;
};