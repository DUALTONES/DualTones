#pragma once
#include "scene.h"

class SceneManager
{
public:
    std::vector<IObject2D> GetObjects();
    void SetScene(Scene* scene);
private:
    Scene* scene;
};