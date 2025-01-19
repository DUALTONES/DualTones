#include "renderables.h"

Sprite2D::~Sprite2D()
{
    
}

void Sprite2D::Draw(Vector2 absolutePosition, float absoluteScale)
{
}

void Sprite2D::SetTexture(Texture2D *texture)
{
    this->texture = texture;
}

void Sprite2D::CalculateDimensions()
{
    dimensions.x = texture->height;
    dimensions.y = texture->width;
}

void Text2D::Draw(Vector2 absolutePosition, float absoluteScale)
{
    
}

RenderCandidate *SpriteStack::AddSprite(std::string name, Sprite2D sprite)
{
    stack.emplace(name, sprite);
    return &stack[name];
}

RenderCandidate *SpriteStack::GetSprite(std::string name)
{
    return &stack[name];
}
