#include "engine.h"
#include <iostream>

void Engine::Init()
{
    
}

void Engine::Update()
{
    engineCore.Compose();
    engineCore.Draw();
}