#pragma once
#include "renderQueue.h"
#include "../debug/messagePool.h"
#include "../core/resources.h"
#include <iostream>

class RenderManager
{
public:
    RenderManager(MessagePool* messagePool, RenderQueue* renderQueue);
    void Update();
    void Draw();
private:
    MessagePool* messagePool;
    Color BackgroundColor = BLACK;
    RenderQueue* renderQueue;
};