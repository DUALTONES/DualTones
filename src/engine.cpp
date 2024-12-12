#include "engine.h"

Engine::Engine()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    InitWindow(1280,720,"DUALTONES");
    SetTargetFPS(60);
}

void Engine::Update()
{
    //engineCore.HandleInput();
    //engineCore.HandleEvents();
    engineCore.Draw();
}