#include "renderManager.h"

RenderManager::RenderManager(RenderQueue* renderQueue)
{
    this->renderQueue = renderQueue;
}

void RenderManager::Update()
{
    BeginDrawing();
    ClearBackground(BLACK);

    Draw();

    EndDrawing();
}

void RenderManager::Draw()
{
    for(RenderCandidate* candidate : renderQueue->GetCandidates())
    {
        if(auto* object = dynamic_cast<IObject2D*>(candidate))
        {
            HandleObject2D(*object);
        }
    }
}

void RenderManager::HandleObject2D(IObject2D& object)
{
    if(auto* object2Dcontainer = dynamic_cast<Object2DContainer*>(&object))
    {
        for(IObject2D& nestedObject : object2Dcontainer->GetObjects())
        {
            HandleObject2D(nestedObject);
        }
    }
    else if(auto* object2D = dynamic_cast<Object2D*>(&object))
    {
        DrawObject2D(*object2D);
    }
}

void RenderManager::DrawObject2D(Object2D& object)
{
    float scale = displayManager->GetScale();
    Vector2 dimensions = Vector2Scale(object.GetDimensions(), scale);
    Vector2 pivotOffset;
    switch (object.GetPivotAlignment())
    {
    case PIVOT_ALIGNMENT::CENTER:
        pivotOffset = {dimensions.x/2*(-1), dimensions.y/2*(-1)};
        break;
    }
    Vector2 absPosition = Vector2Add(displayManager->GetAbsolutePosition(object.GetPosition()), pivotOffset);
    float absScale = scale*object.GetScale();
    object.Draw(absPosition, absScale);
}