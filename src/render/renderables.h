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
    RIGHT_BOTTOM

};

class Renderable
{
public:
    virtual ~Renderable() = default;
};

class Renderable2D : public Renderable
{
public:
    virtual ~Renderable2D() = default;
    virtual void Draw(Vector2 absolutePosition, float absoluteScale) = 0;
    virtual void CalculateDimensions() = 0;
    Vector2 dimensions;
    PIVOT_POINT_2D pivotPoint;
};

class Sprite2D : public Renderable2D
{
public:
    ~Sprite2D();
    void Draw(Vector2 absolutePosition, float absoluteScale) override;
    void SetTexture(Texture2D* texture);
    void CalculateDimensions() override;
protected:
    Texture2D* texture;
};

class Text2D : public Renderable2D
{
public:
    void Draw(Vector2 absolutePosition, float absoluteScale) override;
};

class SpriteStack
{
public:
    Renderable* AddSprite(std::string name, Sprite2D sprite);
    Renderable* GetSprite(std::string name);
private:
    std::unordered_map<std::string, Sprite2D> stack;
};
