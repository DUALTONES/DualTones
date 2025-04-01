#include "composer.h"

Composer::Composer(RenderQueue *renderQueue, DisplayManager *displayManager, Camera2DInternal *camera2D) {
    this->renderQueue = renderQueue;
    this->displayManager = displayManager;
    this->camera2D = camera2D;
}

void Composer::Update()
{
    renderQueue->Flush();
    float scale = displayManager->GetScale();
    for(Scene* scene : scenes) {
        for(Entity* entity : scene->entities) {
            if(entity->renderableType != RENDERABLE_TYPE::NONE) {
                if(entity->transform == ENTITY_TRANSFORM::TRANSFORM_2D) {        
                    Transform2DComponent* transform2DComponent = entity->transform2DComponent;
                    Renderable2D* renderable2D = entity->renderableComponent->renderable2D;
                    float absoluteScale = transform2DComponent->scale;

                    //CHECKS IF RENDERABLE OBEYS GLOBAL SCALE
                    if(true) {
                        absoluteScale *= scale;
                    }

                    //CHECKS IF RENDERABLE OBEYS CAMERA ZOOM
                    if(true) {
                        absoluteScale += camera2D->zoom;
                    }

                    //GETS ABSOLUTE POSITION IN PIXELS OF THE TOP LEFT CORNER OF THE RENDERABLE
                    Vector2 absolutePosition = Vector2Add(
                        displayManager->GetAbsolutePosition(transform2DComponent->poition),
                        Vector2Scale(renderable2D->pivotOffset, absoluteScale)
                    );

                    //CHECKS IF RENDERABLE MOVES WITH CAMERA
                    if(true) {
                        absolutePosition = Vector2Add(
                            absolutePosition,
                            Vector2Scale(
                                displayManager->GetCameraOffset(camera2D->position),
                                (-1) * absoluteScale * (1.0 - transform2DComponent->depth)
                            )
                        );
                    }

                    renderQueue->CreateRenderCandidate(renderable2D, absolutePosition, absoluteScale);
                }
            }
        }
    }
}