#include "scenarioManager.h"

ScenarioManager::ScenarioManager(ResourceManager *resourceManager) {
    this->resourceManager = resourceManager;
}

void ScenarioManager::CreateScenario(std::string name) {
    Scenario* scenario = resourceManager->CreateScenario(name);
    scenarios[name] = scenario;
}

Instruction *ScenarioManager::CreateInstruction(INSTRUCTION_TYPE instructionType, std::vector<std::string> instructionArguments, std::string instructionName) {
    Instruction* instruction = resourceManager->CreateInstruction(instructionName);
    instruction->type = instructionType;
    instruction->arguments = instructionArguments;
    return instruction;
}

void ScenarioManager::CreateInitScript(std::string scenarioName, std::vector<Instruction *> instructions) {
    if(scenarios.find(scenarioName) != scenarios.end()) {
        scenarios[scenarioName]->initScript = resourceManager->CreateScript(scenarioName + "/DUALTONES_INIT");
    }
}

void ScenarioManager::CreateScript(std::string name, std::string scenarioName, std::vector<Instruction *> instructions) {
    if(scenarios.find(scenarioName) != scenarios.end()) {
        Script* script = resourceManager->CreateScript(scenarioName + "/" + name);
        script->instructions = instructions;
        Scenario* scenario = scenarios[scenarioName];
        scenario->scripts[name] = script;
    }
}