#pragma once
#include "engineCore.h"

class Engine
{
public:
    Engine();
    void Update();
private:
    EngineCore engineCore;
};