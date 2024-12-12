#pragma once
#include "includes.h"
#include "object2D.h"

class Scene
{
public:
    Scene();
    ~Scene();
    void AddObject(IObject2D object);
    std::vector<IObject2D> GetObjects();
private:
    std::vector<IObject2D> objects;
};