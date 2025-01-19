#include "composer.h"

Composer::Composer(MessagePool* messagePool, RenderQueue *renderQueue, Scene *activeScene)
{
    this->messagePool = messagePool;
    this->renderQueue = renderQueue;
    this->activeScene = activeScene;
}

void Composer::Update()
{
    renderQueue->Flush();
    if(activeScene != nullptr)
    {
        for(auto& pair : activeScene->entities)
        {
            Entity* entity = &pair.second;
            if(entity->transformComponent != nullptr && entity->renderableComponent != nullptr)
            {
                renderQueue->AddRenderCandidate(entity->transformComponent, entity->renderableComponent);
            }
        }
    }
    else
    {
        messagePool->AddMessage("NO ACTIVE SCENE");
    }
}