#pragma once
#include "../render/renderManager.h"
#include "../composing/composer.h"
#include "resourceManager.h"
#include "../debug/debugManager.h"
#include "../input/inputManager.h"
#include "../controls/controlManager.h"
#include "../controls/dialogueManager.h"

class EngineCore
{
public:
    EngineCore();
    void TEMP_INIT();
    void HandleInput();
    void UpdateGameState();
    void Compose();
    void Draw();
private:
    DebugManager* debugManager;
    MessagePool messagePool;
    Composer* composer;
    Camera2DInternal camera2D;
    DisplayManager displayManager;
    InputManager inputManager;
    ControlManager* controlManager;
    DialogueManager* dialogueManager;
    TimeManager timeManager;
    RenderManager* renderManager;
    ResourceManager* resourceManager;
    Renderable2DStack renderable2DStack;
    TextureStack textureStack;
    FontStack fontStack;
    Scene* activeScene;
    RenderQueue renderQueue;
};