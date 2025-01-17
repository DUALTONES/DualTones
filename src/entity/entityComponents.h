#pragma once
#include "../render/renderCandidate.h"

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
    long positionX;
    long positionY;
    float scale;
    float rotation;
};

class Transform3DComponent : public TransformComponent
{
public:
    long positionX;
    long positionY;
    long positionZ;
};

class RenderableComponent : public EntityComponent
{
public:
    RenderCandidate* renderable;
};