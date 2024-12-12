#include "preRenderManager.h"

PreRenderManager::PreRenderManager(SceneManager *sceneManager, RenderQueue *renderQueue)
{
    this->sceneManager = sceneManager;
    this->renderQueue = renderQueue;
}

void PreRenderManager::Update()
{
    FillRenderQueue();
}

void PreRenderManager::FillRenderQueue()
{
    for (IObject2D& object : sceneManager->GetObjects())
    {
        if (auto* candidate = dynamic_cast<RenderCandidate*>(&object))
        {
            renderQueue->AddCandidate(candidate);
        }
    }
}