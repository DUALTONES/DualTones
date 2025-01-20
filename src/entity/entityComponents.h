#pragma once
#include "../render/renderables.h"

enum class ENTITY_TRANSFORM
{
    TRANSFORM_2D,
    TRANSFORM_3D,
    NONE
};

enum class ENTITY_RENDERABLE
{
    SPRITE_2D,
    TEXT_2D
};

class EntityComponent
{
public:
    virtual ~EntityComponent() = default;
};

class TransformComponent : public EntityComponent
{
public:
    virtual ~TransformComponent() = default;
};

class Transform2DComponent : public TransformComponent
{
public:
    Vector2 position;
    float scale;
    float rotation;
};

class Transform3DComponent : public TransformComponent
{
public:
    Vector3 position;
};

class RenderableComponent : public EntityComponent
{
public:
    RenderableComponent() = default;
    RenderableComponent(Renderable* renderable);
    Renderable* renderable;
};