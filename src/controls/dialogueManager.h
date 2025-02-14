#pragma once
#include "timeManager.h"
#include "../core/resourceManager.h"
#include <iostream>

class DialogueManager
{
public:
    DialogueManager(TimeManager* timeManager, ResourceManager* resourceManager);
    void Init();
    void Update();
private:
    Entity* displayedTextEntity;
    int index = 0;
    bool updatingLine = false;
    //TEMP SOLUTION JUST FOR TEST
    std::string newLine = "I USE RUST BTW... AND ARCH!! HELL YEAH... AND NEOVIM!!";
    std::string displayedLine;
    TimeManager* timeManager;
    ResourceManager* resourceManager;
};