#include "dialogueManager.h"

DialogueManager::DialogueManager(TimeManager *timeManager)
{
    this->timeManager = timeManager;
}

void DialogueManager::Update()
{
    if(displayedLine != newLine)
    {
        if(!updatingLine)
        {
            if(timeManager->GetTimerState("DIALOGUE_LINE_CHARACTER_UPDATE"))
            {
                updatingLine = false;
                //std::cout << "UPDATING" << std::endl;
                displayedLine += newLine[index];
                index++;
            }
        }
        else
        {
            timeManager->AddTimer("DIALOGUE_LINE_CHARACTER_UPDATE", 30);
            updatingLine = true;
        }
    }
    else
    {
        index = 0;
    }
    //std::cout << displayedLine << std::endl;
}