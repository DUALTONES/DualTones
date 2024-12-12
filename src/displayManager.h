#pragma once
#include "imanager.h"

class DisplayManager : public IManager
{
public:
    DisplayManager(Vector2 referenceResolution, Vector2 relativeCoordinates);
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