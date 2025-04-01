#pragma once

#include "entityComponents.h"

class Entity : public Resource {
public:
    ENTITY_TRANSFORM transform = ENTITY_TRANSFORM::NONE;
    RENDERABLE_TYPE renderableType = RENDERABLE_TYPE::NONE;
    Transform2DComponent* transform2DComponent = nullptr;
    Transform3DComponent* transform3DComponent = nullptr;
    RenderableComponent* renderableComponent = nullptr;
    TextAttributeComponent* textAttributeComponent = nullptr;
};