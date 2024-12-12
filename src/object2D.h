#pragma once
#include "includes.h"
#include "renderCandidate.h"

enum class PIVOT_ALIGNMENT
{
    CENTER,
    LEFT_TOP,
    RIGHT_TOP,
    LEFT_BOTTOM,
    RIGHT_BOTTOM,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

class IObject2D : public RenderCandidate
{
public:
    void SetPosition(Vector2 position);
    Vector2 GetPosition();
    void SetScale(float scale);
    float GetScale();
    void SetRotation(float rotation);
    float GetRotation();
protected:
    Vector2 position;
    float scale;
    float rotation;
};

class Object2D : public IObject2D
{
public:
    Object2D(PIVOT_ALIGNMENT pivotAlignment = PIVOT_ALIGNMENT::CENTER);
    virtual void Draw(Vector2 absPosition, float absScale) = 0;
    virtual void CalculateDimensions() = 0;
    Vector2 GetDimensions();
    PIVOT_ALIGNMENT GetPivotAlignment();
protected:
    Vector2 dimensions;
private:
    PIVOT_ALIGNMENT pivotAlignment;
};

class Object2DContainer : public IObject2D
{
public:
    Object2DContainer();
    std::vector<IObject2D> GetObjects();
    void AddObject(IObject2D object);
private:
    std::vector<IObject2D> objects;
};

class Sprite : public Object2D
{
public:
    void Draw(Vector2 absPosition, float absScale) override;
    void CalculateDimensions() override;
    void SetImage(Texture2D image);
private:
    Texture2D image;
};