#pragma once
#include <unordered_map>
#include <string>
#include "raylib/raylib.h"

enum class PIVOT_POINT_2D
{
    CENTER,
    LEFT_TOP,
    LEFT_MIDDLE,
    LEFT_BOTTOM,
    RIGHT_TOP,
    RIGHT_MIDDLE,
    RIGHT_BOTTOM,
    TOP_MIDDLE,
    BOTTOM_MIDDLE
};

enum class RENDERABLE_TYPE
{
    NONE,
    TEXTURE,
    TEXT
};

class Renderable
{
public:
    virtual ~Renderable() = default;
};

class TextAttributes
{
public:
    std::string text;
    Font* font;
    float fontSize;
    float spacing;
};

class Renderable2DAttributes
{
public:
    Vector2 dimensions = {0, 0};
    Vector2 pivotOffset = {0, 0};
    PIVOT_POINT_2D pivotPoint;
    Texture2D* texture = nullptr;
    TextAttributes* textAttributes = nullptr;
    RENDERABLE_TYPE renderableType;
};

class Renderable2D : public Renderable
{
public:
    void Draw(Vector2 absolutePosition, float absoluteScale);
    void CalculateDimensions();
    void CalculateOffset();
    Renderable2DAttributes* renderable2DAtrributes;
};

class Renderable2DStack
{
public:
    void AddRenderable2D(std::string name, RENDERABLE_TYPE renderableType);
    Renderable2D* GetRenderable2D(std::string name);
private:
    Renderable2DAttributes* AddRenderable2DAttributes(std::string name);
    TextAttributes* AddTextAttributes(std::string name);
    std::unordered_map<std::string, Renderable2D> stack;
    std::unordered_map<std::string, Renderable2DAttributes> attributesStack;
    std::unordered_map<std::string, TextAttributes> textAttributesStack;
};