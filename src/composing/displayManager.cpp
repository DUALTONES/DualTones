#include "displayManager.h"

void DisplayManager::SetReferenceResolution(Vector2 referenceResolution)
{
    this->referenceResolution = referenceResolution;
}

void DisplayManager::SetRelativeCoordinats(Vector2 relativeCoordinates)
{
    this->relativeCoordinates = relativeCoordinates;
}

void DisplayManager::Update()
{
    CalculateResolution();
}

void DisplayManager::CalculateResolution()
{
    Vector2 newResolution;
    newResolution = {float(GetScreenWidth()), float(GetScreenHeight())};
    if(!Vector2Equals(newResolution, resolution))
    {
        resolution = newResolution;
        halfResolution = Vector2Scale(resolution, 0.5f);
        CalculateScale();
    }
}

void DisplayManager::CalculateScale()
{
    relativeScale = Vector2Divide(resolution, relativeCoordinates);
    scale = std::min(resolution.x/referenceResolution.x,resolution.y/referenceResolution.y);
}

float DisplayManager::GetScale()
{
    return scale;
}

Vector2 DisplayManager::GetResolution()
{
    return resolution;
}

Vector2 DisplayManager::GetAbsolutePosition(Vector2 position)
{
    return {(position.x * relativeScale.x) + halfResolution.x, (position.y * relativeScale.y) + halfResolution.y};
}