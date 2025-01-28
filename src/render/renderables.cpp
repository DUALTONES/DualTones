#include "renderables.h"

void Renderable2D::Draw(Vector2 absolutePosition, float absoluteScale)
{
    switch (renderable2DAtrributes->renderableType)
    {
        case RENDERABLE_TYPE::TEXTURE:
        {
            DrawTextureEx(*renderable2DAtrributes->texture, absolutePosition, 0.0f, absoluteScale, WHITE);
            break;
        }
        case RENDERABLE_TYPE::TEXT:
        {
            DrawTextEx(*renderable2DAtrributes->textAttributes->font, renderable2DAtrributes->textAttributes->text.c_str(),
            absolutePosition, renderable2DAtrributes->textAttributes->fontSize * absoluteScale,
            renderable2DAtrributes->textAttributes->spacing * absoluteScale, WHITE);
            break;
        }
    }
}

void Renderable2D::CalculateDimensions()
{
    switch(renderable2DAtrributes->renderableType)
    {
        case RENDERABLE_TYPE::TEXTURE:
        {
            renderable2DAtrributes->dimensions = {(float)renderable2DAtrributes->texture->width, (float)renderable2DAtrributes->texture->height};
            break;
        }
        case RENDERABLE_TYPE::TEXT:
        {
            renderable2DAtrributes->dimensions = {MeasureTextEx(*renderable2DAtrributes->textAttributes->font,
            renderable2DAtrributes->textAttributes->text.c_str(),renderable2DAtrributes->textAttributes->fontSize, renderable2DAtrributes->textAttributes->spacing)};
            break;
        }
    }
    CalculateOffset();
}

void Renderable2D::CalculateOffset()
{
    switch (renderable2DAtrributes->pivotPoint)
    {
        case PIVOT_POINT_2D::CENTER:
        {
            renderable2DAtrributes->pivotOffset = {renderable2DAtrributes->dimensions.x / 2 * (-1), renderable2DAtrributes->dimensions.y / 2 * (-1)};
            break;
        }
        case PIVOT_POINT_2D::LEFT_TOP:
        {
            renderable2DAtrributes->pivotOffset = {0, 0};
            break;
        }
        case PIVOT_POINT_2D::LEFT_MIDDLE:
        {
            renderable2DAtrributes->pivotOffset = {0, renderable2DAtrributes->dimensions.y / 2 * (-1)};
            break;
        }
        case PIVOT_POINT_2D::LEFT_BOTTOM:
        {
            renderable2DAtrributes->pivotOffset = {0, renderable2DAtrributes->dimensions.y * (-1)};
            break;
        }
        case PIVOT_POINT_2D::RIGHT_TOP:
        {
            renderable2DAtrributes->pivotOffset = {renderable2DAtrributes->dimensions.x * (-1), 0};
            break;
        }
        case PIVOT_POINT_2D::RIGHT_MIDDLE:
        {
            renderable2DAtrributes->pivotOffset = {renderable2DAtrributes->dimensions.x * (-1), renderable2DAtrributes->dimensions.y / 2 * (-1)};
            break;
        }
        case PIVOT_POINT_2D::RIGHT_BOTTOM:
        {
            renderable2DAtrributes->pivotOffset = {renderable2DAtrributes->dimensions.x * (-1), renderable2DAtrributes->dimensions.y * (-1)};
            break;
        }
    }
}

void Renderable2DStack::AddRenderable2D(std::string name, RENDERABLE_TYPE renderableType)
{
    Renderable2D renderable2D;
    renderable2D.renderable2DAtrributes = AddRenderable2DAttributes(name);
    renderable2D.renderable2DAtrributes->renderableType = renderableType;
    if(renderableType == RENDERABLE_TYPE::TEXT)
    {
        renderable2D.renderable2DAtrributes->textAttributes = AddTextAttributes(name);
    }
    stack.emplace(name, renderable2D);
}

Renderable2D *Renderable2DStack::GetRenderable2D(std::string name)
{
    if(stack.find(name) == stack.end())
    {
        return nullptr;
    }
    return &stack[name];
}

Renderable2DAttributes *Renderable2DStack::AddRenderable2DAttributes(std::string name)
{
    Renderable2DAttributes renderableAttributes;
    attributesStack.emplace(name, renderableAttributes);
    return &attributesStack[name];
}

TextAttributes *Renderable2DStack::AddTextAttributes(std::string name)
{
    TextAttributes textAttributes;
    textAttributesStack.emplace(name, textAttributes);
    return &textAttributesStack[name];
}