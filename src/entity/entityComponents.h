#pragma once
#include "../render/renderables.h"

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
