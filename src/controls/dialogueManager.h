#pragma once
#include "timeManager.h"
#include <iostream>

class DialogueManager
{
public:
    DialogueManager(TimeManager* timeManager);
    void Update();
private:
    int index = 0;
    bool updatingLine = false;
    std::string newLine = "IWEIJWEGJIOWEJGIWJEIGJWEGIO";
    std::string displayedLine;
    TimeManager* timeManager;
};