#pragma once

#include "instruction.h"

class Script : public Resource {
public:
    std::vector<Instruction*> instructions;
};