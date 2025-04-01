#include "engineCore.h"

EngineCore::EngineCore() {
    scenarioManager = new ScenarioManager(&resourceManager);
    vanillaInterpreter = new VanillaInterpreter(scenarioManager);
    composer = new Composer(&renderQueue, &displayManager, &camera2D);
    renderManager = new RenderManager(&renderQueue);
    TEMP_INIT();
}

void EngineCore::VanillaReadScenario(std::string path) {
    vanillaInterpreter->ParseFile(path);
}

void EngineCore::TEMP_INIT() {
    VanillaReadScenario("../scripts/rookieTest2.vanilla");
    resourceManager.Display();
}

void EngineCore::Compose() {
    composer->Update();
}

void EngineCore::Draw() {
    renderManager->Update();
}
