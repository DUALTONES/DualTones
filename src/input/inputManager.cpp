#include "inputManager.h"

void InputManager::Update()
{
    inputEventsList.clear();
    HandleKeyInput();
    HandleMouseInput();
    HandleTouchInput();
}

void InputManager::HandleKeyInput()
{
    for(auto &[_, keyBind] : inputMap->inputMap)
    {
        if(IsKeyPressed(keyBind.key))
        {
            if(keyBind.combinationKey == nullptr)
            {
                if(keyBind.isHeld)
                {
                    if(keyBind.isHoldable)
                    {
                        inputEventsList.push_back(keyBind.holdEvent);
                    }
                }
                else
                {
                    inputEventsList.push_back(keyBind.pressEvent);
                    keyBind.isHeld = true;
                }
            }
            else
            {
                
            }
        }
        else
        {
            if(keyBind.isHeld)
            {
                inputEventsList.push_back(keyBind.unpressEvent);
                keyBind.isHeld = false;
            }
        }
    }
}

void InputManager::HandleMouseInput()
{
    mousePosition = GetMousePosition();

    mouseDelta = GetMouseDelta();
    
    if(IsKeyPressed(MOUSE_BUTTON_LEFT))
    {
        
    }
    if(IsKeyPressed(MOUSE_BUTTON_RIGHT))
    {
        
    }
    if(IsKeyPressed(MOUSE_BUTTON_MIDDLE))
    {
        
    }
    if(IsKeyPressed(MOUSE_BUTTON_FORWARD))
    {
        
    }
}

void InputManager::HandleTouchInput()
{
    
}