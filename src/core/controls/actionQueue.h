#pragma once

#include <vector>
#include "action.h"

class ActionQueue {
public:
    void Flush();
    void AddAction(Action* action);
    std::vector<Action*> queue;
};