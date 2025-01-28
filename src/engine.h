#pragma once
#include "core/engineCore.h"

class Engine
{
public:
    void Update();
private:
    EngineCore engineCore;
    long frames = 0;
};