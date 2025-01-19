#pragma once
#include "raylib/raylib.h"
#include "raylib/raymath.h"

class DisplayManager
{
public:
    void SetReferenceResolution(Vector2 referenceResolution);
    void SetRelativeCoordinats(Vector2 relativeCoordinats);
    void Update();
    void GetResolution();
    float GetScale();
    Vector2 GetAbsolutePosition(Vector2 position);
private:
    void CalculateScale();
    Vector2 referenceResolution;
    Vector2 resolution;
    Vector2 halfResolution;
    Vector2 relativeCoordinates;
    Vector2 relativeScale;
    float scale;
};