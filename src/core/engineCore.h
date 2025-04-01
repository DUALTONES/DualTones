#pragma once

#include "resourceManager.h"
#include "../composing/composer.h"
#include "../render/renderManager.h"
#include "controls/scripting/VANILLASCRIPT/vanillaInterpreter.h"

class EngineCore {
public:
    EngineCore();
    void VanillaReadScenario(std::string path);
    void TEMP_INIT();
    void Compose();
    void Draw();
private:
    ResourceManager resourceManager;
    ScenarioManager* scenarioManager;
    VanillaInterpreter* vanillaInterpreter;
    DisplayManager displayManager;
    RenderQueue renderQueue;
    Camera2DInternal camera2D;
    Composer* composer;
    RenderManager* renderManager;
};