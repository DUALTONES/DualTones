#pragma once
#include "includes.h"
#include "renderQueue.h"
#include "imanager.h"
#include "sceneManager.h"

class PreRenderManager : public IManager
{
public:
    PreRenderManager(SceneManager* sceneManager, RenderQueue* renderQueue);
    void Update();
private:
    void FillRenderQueue();
    SceneManager* sceneManager;
    RenderQueue* renderQueue;
};