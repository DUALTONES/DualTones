#pragma once
#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include <iostream>

class DisplayManager
{
public:
    void SetReferenceResolution(Vector2 referenceResolution);
    void SetRelativeCoordinats(Vector2 relativeCoordinates);
    void Update();
    void CalculateResolution();
    float GetScale();
    Vector2 GetResolution();
    Vector2 GetAbsolutePosition(Vector2 position);
    Vector2 GetRelativePosition(Vector2 position);
    Vector2 GetCameraOffset(Vector2 position);
private:
    void CalculateScale();
    Vector2 referenceResolution;
    Vector2 resolution;
    Vector2 halfResolution;
    Vector2 relativeCoordinates;
    Vector2 relativeScale;
    float scale;
};