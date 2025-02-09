#include "engine.h"
#include <iostream>

void Engine::Update()
{
    engineCore.HandleInput();
    engineCore.UpdateGameState();
    engineCore.Compose();
    engineCore.Draw();
}