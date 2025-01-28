#include "renderManager.h"

RenderManager::RenderManager(MessagePool* messagePool, RenderQueue *renderQueue)
{
    this->messagePool = messagePool;
    this->renderQueue = renderQueue;
}

void RenderManager::Update()
{
    BeginDrawing();
    ClearBackground(BackgroundColor);

    Draw();

    EndDrawing();
}

void RenderManager::Draw()
{
    for(const RenderCandidate& renderCandidate : renderQueue->queue)
    {
        if(Renderable2D* renderable = dynamic_cast<Renderable2D*>(renderCandidate.renderable))
        {
            renderable->Draw(renderCandidate.absolutePosition, renderCandidate.absoluteScale);
        }
    }
}