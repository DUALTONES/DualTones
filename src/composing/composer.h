#pragma once
#include "../render/renderQueue.h"
#include "scene.h"
#include "../debug/messagePool.h"

class Composer
{
public:
    Composer(MessagePool* messagePool, RenderQueue* renderQueue, Scene* activeScene);
    void Update();
private:
    MessagePool* messagePool;
    RenderQueue* renderQueue;
    Scene* activeScene;
};