#pragma once

#include <vector>
#include <string>
#include "../core/resource.h"

class TextAttributes : public Resource {
public:
    std::string text;
    Font* font = nullptr;
    float fontSize;
    float spacing;
    bool hasFill = false;
    Color* textColor = nullptr;
    Color* fillColor = nullptr;
    Color* outlineColor = nullptr;
};

class Renderable2D : public Resource {
public:
    void Draw(Vector2 absolutePosition, float absoluteScale);
    void CalculateDimensions();
    void CalculateOffset();
    RENDERABLE_TYPE type;
    Vector2 dimensions = {0, 0};
    Vector2 halfDimensions = {0, 0};
    Vector2 pivotOffset = {0, 0};
    Vector2 pivotPoint = {0, 0};
    Texture2D* texture = nullptr;
    TextAttributes* textAttributes = nullptr;
};