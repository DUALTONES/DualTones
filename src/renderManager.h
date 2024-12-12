#pragma once
#include "includes.h"
#include "imanager.h"
#include "displayManager.h"
#include "object2D.h"
#include "renderQueue.h"

class RenderManager : public IManager
{
public:
    RenderManager(RenderQueue* renderQueue);
    void Update();
private:
    void Draw();
    void HandleObject2D(IObject2D& object);
    void DrawObject2D(Object2D& object);
    DisplayManager* displayManager;
    RenderQueue* renderQueue;
};