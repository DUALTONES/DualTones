#include "engine.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    SetTargetFPS(60);
    InitWindow(1280,720,"DualTones Engine v0.1.5");
    Engine engine;

    while(!WindowShouldClose())
    {
        engine.Update();
    }
};