#include "engine.h"

int main()
{
    Engine engine;
    while (!WindowShouldClose())
    {
        engine.Update();
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    } 
}