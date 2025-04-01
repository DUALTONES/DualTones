#pragma once

#include "renderQueue.h"

class RenderManager {
public:
    RenderManager(RenderQueue* renderQueue);
    void Update();
    void Draw();
private:
    RenderQueue* renderQueue;
};