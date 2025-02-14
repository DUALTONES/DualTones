#include "composer.h"

Composer::Composer(MessagePool *messagePool, RenderQueue *renderQueue, DisplayManager* displayManager, Camera2DInternal* camera2D)
{
    this->messagePool = messagePool;
    this->renderQueue = renderQueue;
    this->displayManager = displayManager;
    this->camera2D = camera2D;
}

void Composer::Update()
{
    renderQueue->Flush();
    float scale = displayManager->GetScale();
    for(Scene* scene : scenes)
    {
        for(const std::pair<std::string, Entity>& pair : scene->entities)
        {
            const Entity& entity = pair.second;
            if(Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(entity.renderableComponent->renderable))
            {
                if(Transform2DComponent* transform2DComponent = dynamic_cast<Transform2DComponent*>(entity.transformComponent))
                {
                    float absoluteScale = scale * transform2DComponent->scale;
                    if(!transform2DComponent->lockToScreen)
                        absoluteScale += camera2D->zoom;
                    Vector2 absolutePosition = Vector2Add(displayManager->GetAbsolutePosition(transform2DComponent->position),
                    Vector2Scale(entity.renderableAttributesComponent->renderableAttributes->pivotOffset, absoluteScale));
                    if(!transform2DComponent->lockToScreen)
                        absolutePosition = Vector2Add(absolutePosition, Vector2Scale(displayManager->GetCameraOffset(camera2D->position),
                        (-1) * absoluteScale * (1.0 - transform2DComponent->depth)));
                    renderQueue->CreateRenderCandidate(renderable2D, absolutePosition, absoluteScale);
                }
            }
        }
    }
}

void Composer::SetScenes(std::vector<Scene *> scenes)
{
    this->scenes = scenes;
}