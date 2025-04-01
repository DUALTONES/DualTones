#include "engine.h"

void Engine::Update() {
    engineCore.Compose();
    engineCore.Draw();
}