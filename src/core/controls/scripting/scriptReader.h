#pragma once

#include "scenario.h"
#include "../actionQueue.h"

class ReadCandidate {
public:
    Script* script;
    int instructionIndex = 0;
    bool isHeld = false;
};

class ScriptReader {
public:
    void Update();
    void ReadInstruction(Instruction* instruction);
private:
    Scenario* currentScenario;
    std::unordered_map<std::string, ReadCandidate> scriptsToRead;
    ActionQueue* actionQueue;
};