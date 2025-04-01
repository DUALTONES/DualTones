#pragma once

#include "../render/renderable.h"
#include "../core/resource.h"

class NodeComponent {
    NodeComponent* parent;
};

class Transform2DComponent : public Resource {
public:
    Vector2 poition = {0, 0};
    float scale = 1.0f;
    float rotation = 0.0f;
    float depth;
};

class Transform3DComponent : public Resource {
public:
    Vector3 position = {0, 0, 0};
    float scale = 1.0f;
    Vector3 rotation = {0, 0, 0};
};

class RenderableComponent : public Resource {
public:
    void SetPivotPoint(Vector2 pivotPoint);
    void SetTexture(Texture2D* texture);
    Renderable2D* renderable2D;
};

class TextAttributeComponent : public Resource {
public:
    void SetText(std::string text);
    void SetFont(Font* font);
    void SetFontSize(float fontSize);
    void SetSpacing(float spacing);
    void SetFill(bool hasFill);
    void SetTextColor(Color* textColor);
    void SetFillColor(Color* fillColor);
    void SetOutlineColor(Color* outineColor);
    TextAttributes* textAttributes;
};