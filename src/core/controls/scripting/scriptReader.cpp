#include "scriptReader.h"

void ScriptReader::Update() {
    actionQueue->Flush();
    for(std::pair<std::string, ReadCandidate> pair : scriptsToRead) {
        Script* script = pair.second.script;
        for(Instruction* instruction : script->instructions) {
            ReadInstruction(instruction);
        }
    }
}

void ScriptReader::ReadInstruction(Instruction *instruction) {
    switch(instruction->type) {
        case INSTRUCTION_TYPE::CREATE_RESOURCE : {
            RESOURCE_TYPE resourceType = (RESOURCE_TYPE)std::stoi(instruction->arguments[0]);
            switch(resourceType) {
                case RESOURCE_TYPE::TEXTURE : {
                    std::string textureName = instruction->arguments[1];
                    std::string path = instruction->arguments[2];
                    Action* action = new ActionLoadTexture(textureName, path);
                    actionQueue->AddAction(action);
                }
                case RESOURCE_TYPE::SCENE : {
                    std::string sceneName = instruction->arguments[1];
                    Action* action = new ActionCreateScene(sceneName);
                }
            }
            break;            
        }
        default: {
            break;
        }
    }
}