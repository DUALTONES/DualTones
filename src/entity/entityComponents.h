#pragma once
#include "../render/renderables.h"

enum class ENTITY_TRANSFORM
{
    TRANSFORM_2D,
    TRANSFORM_3D,
    NONE
};

class EntityComponent
{
public:
    bool updating = false;
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
    Vector2 position = {0, 0};
    float scale = 1.0f;
    float rotation = 0.0f;
};

class Transform3DComponent : public TransformComponent
{
public:
    Vector3 position = {0, 0, 0};
    float scale = 1.0f;
};

class RenderableComponent : public EntityComponent
{
public:
    Renderable* renderable;
};

class RenderableAttributesComponent : public EntityComponent
{
public:
    Renderable2DAttributes* renderableAttributes;
};

class TextAttributesComponent : public EntityComponent
{
public:
    TextAttributes* textAttributes;
};