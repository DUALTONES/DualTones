#include "engine.h"
#include <iostream>

void Engine::Update()
{
    engineCore.Compose();
    engineCore.Draw();
}