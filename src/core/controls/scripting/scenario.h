#pragma once

#include <unordered_map>
#include "script.h"

class Scenario  : public Resource {
public:
    std::string name;
    Script* initScript;
    std::unordered_map<std::string, Script*> scripts;
};