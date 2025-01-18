#pragma once
#include <unordered_map>
#include <string>
#include "raylib/raylib.h"

class RenderCandidate
{
public:
    virtual ~RenderCandidate() = default;
};

class RenderCandidate2D : public RenderCandidate
{
public:
    virtual void Draw(Vector2 absolutePosition, float absoluteScale) = 0;
    virtual ~RenderCandidate2D() = default;
};

class Sprite2D : public RenderCandidate2D
{
public:
    ~Sprite2D();
    void Draw(Vector2 absolutePosition, float absoluteScale) override;
    void SetTexture(Texture2D* texture);
protected:
    Texture2D* texture;
};

class Text2D : public RenderCandidate2D
{
public:
    void Draw(Vector2 absolutePosition, float absoluteScale) override;
};

class SpriteStack
{
public:
    RenderCandidate* AddSprite(std::string name, Sprite2D sprite);
private:
    std::unordered_map<std::string, Sprite2D> stack;
};