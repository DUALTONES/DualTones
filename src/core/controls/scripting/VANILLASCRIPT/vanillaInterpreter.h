#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../scenarioManager.h"

const int VECTOR_FIND_FAIL = -1;

enum class VANILLA_ACTION {
    SCENARIO,
    SCRIPT,
    GO_TO,
    CREATE,
    MODIFY,
    START,
    END,
};

static std::vector<std::string> VANILLA_ACTION_NAMES = {
    "SCENARIO",
    "SCRIPT",
    "GO_TO",
    "CREATE",
    "MODIFY",
    "START",
    "END",
};

int FindStringInVector(std::string targetString, std::vector<std::string>targetVector);

class VanillaInterpreter {
public:
    VanillaInterpreter(ScenarioManager* scenarioManager);
    void ParseFile(std::string path);
    void HandleCodeLine(std::vector<std::string> codeLine);
    void AddInstruction(INSTRUCTION_TYPE instructionType, std::vector<std::string> arguments);
private:
    bool initScript = false;
    int instructionIndex = 1;
    std::string currentScenario;
    std::string currentScript;
    ScenarioManager* scenarioManager;
    std::vector<Instruction*> instructions;
};