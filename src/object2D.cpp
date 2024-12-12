#include "object2D.h"

void IObject2D::SetPosition(Vector2 position)
{
    this->position = position;
}

Vector2 IObject2D::GetPosition()
{
    return position;
}

void IObject2D::SetScale(float scale)
{
    this->scale = scale;
}

float IObject2D::GetScale()
{
    return scale;
}

void IObject2D::SetRotation(float rotation)
{
    this->rotation = rotation;
}

float IObject2D::GetRotation()
{
    return rotation;
}

Object2D::Object2D(PIVOT_ALIGNMENT pivotAlignment)
{
    
}

Vector2 Object2D::GetDimensions()
{
    return dimensions;
}

PIVOT_ALIGNMENT Object2D::GetPivotAlignment()
{
    return pivotAlignment;
}

Object2DContainer::Object2DContainer()
{
    
}

std::vector<IObject2D> Object2DContainer::GetObjects()
{
    return objects;
}

void Object2DContainer::AddObject(IObject2D object)
{
    objects.push_back(object);
}

void Sprite::Draw(Vector2 absPosition, float absScale)
{
    DrawTextureEx(image,absPosition,rotation,absScale,WHITE);
}

void Sprite::CalculateDimensions()
{
    dimensions = {image.width * scale, image.height * scale};
}

void Sprite::SetImage(Texture2D image)
{
    this->image = image;
}