#include "renderManager.h"

RenderManager::RenderManager(RenderQueue *renderQueue) {
    this->renderQueue = renderQueue;
}

void RenderManager::Update() {
    BeginDrawing();
    ClearBackground(BLACK);

    Draw();

    EndDrawing();
}

void RenderManager::Draw() {
    for(const RenderCandidate& renderCandidate : renderQueue->queue) {
        renderCandidate.renderable2D->Draw(renderCandidate.absolutePosition, renderCandidate.absoluteScale);
    }
}