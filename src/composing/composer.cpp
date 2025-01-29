#include "composer.h"

Composer::Composer(MessagePool *messagePool, RenderQueue *renderQueue, DisplayManager* displayManager)
{
    this->messagePool = messagePool;
    this->renderQueue = renderQueue;
    this->displayManager = displayManager;
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
                    Vector2 absolutePosition = Vector2Add(displayManager->GetAbsolutePosition(transform2DComponent->position),
                    Vector2Scale(entity.renderableAttributesComponent->renderableAttributes->pivotOffset, absoluteScale));
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