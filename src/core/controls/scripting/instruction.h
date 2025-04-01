#pragma once

#include <string>
#include <vector>
#include "../../resource.h"

enum class INSTRUCTION_TYPE {
    GO_TO_SCRIPT,
    CREATE_RESOURCE,
};

class Instruction : public Resource {
public:
    INSTRUCTION_TYPE type;
    std::vector<std::string> arguments;
};