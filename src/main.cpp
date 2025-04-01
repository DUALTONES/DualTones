#include "engine.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    InitWindow(1280,720,"DualTones Engine v0.2");
    Engine engine;

    while(!WindowShouldClose()) {
        engine.Update();
    }
}