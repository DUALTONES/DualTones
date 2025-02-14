#include "dialogueManager.h"

DialogueManager::DialogueManager(TimeManager *timeManager, ResourceManager* resourceManager)
{
    this->timeManager = timeManager;
    this->resourceManager = resourceManager;
}

void DialogueManager::Init()
{
    displayedTextEntity = resourceManager->CreateEntity("DIALOGUE_LINE", "GUI", ENTITY_TRANSFORM::TRANSFORM_2D, RENDERABLE_TYPE::TEXT);
    resourceManager->AddTextToEntity("DIALOGUE_LINE", "GUI", "DIALOGUE_TEXT", "TESTFONT", 13, 0, true);
    resourceManager->ModifyEntityPosition("DIALOGUE_LINE", "GUI", {0, -35});
}

void DialogueManager::Update()
{
    if(displayedLine != newLine)
    {
        if(updatingLine)
        {
            if(timeManager->GetTimerState("DIALOGUE_LINE_CHARACTER_UPDATE"))
            {
                updatingLine = false;
                std::cout << "UPDATING" << std::endl;
                displayedLine += newLine[index];
                std::cout << displayedLine << std::endl;
                index++;
                displayedTextEntity->textAttributesComponent->textAttributes->text = displayedLine;
                Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(displayedTextEntity->renderableComponent->renderable);
                renderable2D->CalculateDimensions();
            }
        }
        else
        {
            timeManager->AddTimer("DIALOGUE_LINE_CHARACTER_UPDATE", 0.05);
            updatingLine = true;
        }
    }
    else
    {
        index = 0;
    }
}