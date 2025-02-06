#pragma once
#include "inputMap.h"
#include <vector>
#include "raylib/raylib.h"

class InputManager
{
public:
    void Update();
    void HandleKeyInput();
    void HandleMouseInput();
    void HandleTouchInput();
    std::vector<int> inputEventsList;
    Vector2 mousePosition;
    Vector2 mouseDelta;
private:
    InputMap* inputMap;
};