#pragma once

#include "raylib/raylib.h"
#include "raylib/raymath.h"

enum class RESOURCE_TYPE {
    SCENARIO,
    INSTRUCTION,
    SCRIPT,
    TEXTURE,
    FONT,
    COLOR,
    SCENE,
    ENTITY,
    ENTITY_COMPONENT_TRANSFORM_2D,
    ENTITY_COMPONENT_TRANSFORM_3D,
    ENTITY_COMPONENT_RENDERABLE,
    ENTITY_COMPONENT_TEXT_ATTRIBUTES,
    RENDERABLE_2D,
    TEXT_ATTRIBUTES,
};

enum class RENDERABLE_TYPE
{
    NONE,
    TEXTURE,
    TEXT
};

enum class ENTITY_TRANSFORM {
    NONE,
    TRANSFORM_2D,
    TRANSFORM_3D,
};

class Resource {
public:
    virtual ~Resource() = default;
    std::string name;
    RESOURCE_TYPE type;
};

class TextureResource : public Resource {
public:
    Texture2D texture;
};

class FontResource : public Resource {
public:
    Font font;
};

class ColorResource : public Resource {
public:
    Color color;
};