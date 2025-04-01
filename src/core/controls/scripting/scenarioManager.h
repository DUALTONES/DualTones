#pragma once

#include "scenario.h"
#include "../../resourceManager.h"

class ScenarioManager {
public:
    ScenarioManager(ResourceManager* resourceManager);
    void CreateScenario(std::string name);
    Instruction* CreateInstruction(INSTRUCTION_TYPE instructionType, std::vector<std::string> instructionArguments, std::string instructionName);
    void CreateInitScript(std::string scenarioName, std::vector<Instruction*> instructions);
    void CreateScript(std::string name, std::string scenarioName, std::vector<Instruction*> instructions);
private:
    std::unordered_map<std::string, Scenario*> scenarios;
    ResourceManager* resourceManager;
};