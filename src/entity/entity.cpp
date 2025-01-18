#include "entity.h"

Entity::Entity()
{
    
}

void Entity::AddTransformComponent(TransformComponent *transformComponent)
{
    this->transformComponent = transformComponent;
}

void Entity::AddRenderableComponent(RenderableComponent *renderableComponent)
{
    this->renderableComponent = renderableComponent;
}
