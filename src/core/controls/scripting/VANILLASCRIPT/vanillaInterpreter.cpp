#include "vanillaInterpreter.h"

int FindStringInVector(std::string targetString, std::vector<std::string> targetVector) {
    for(int i = 0; i < targetVector.size(); i ++) {
        if(targetString == targetVector[i]) {
            return i;            
        }
    }
    return VECTOR_FIND_FAIL;
}

VanillaInterpreter::VanillaInterpreter(ScenarioManager *scenarioManager) {
    this->scenarioManager = scenarioManager;
}

void VanillaInterpreter::ParseFile(std::string path)
{
    bool ignore = false;
    std::ifstream file(path);
    std::vector<std::vector<std::string>> code;
    std::vector<std::string> codeLine;
    if(file) {        
        std::string line;
        while (file >> line)
        {
            if(line == "#") {
                if(ignore) {
                    ignore = false;
                    continue;
                }
                else
                    ignore = true;
            }
            if(line == "!") {
                code.push_back(codeLine);
                codeLine.clear();
                continue;
            }
            if(!ignore && line != "") {
                codeLine.push_back(line);
            }
        }
    } else {
        std::cout << "can't open file" << std::endl;
    }
    file.close();

    for(std::vector<std::string> codeLine : code) {
        HandleCodeLine(codeLine);
        for (std::string token : codeLine) {
            std::cout << token << " ";
        }
        std::cout << "\n";
    }
}

void VanillaInterpreter::HandleCodeLine(std::vector<std::string> codeLine) {
    std::string actionToken = codeLine[0];
    int action = FindStringInVector(actionToken, VANILLA_ACTION_NAMES);
    if(action != VECTOR_FIND_FAIL) {
        switch(VANILLA_ACTION(action)) {
            case VANILLA_ACTION::SCENARIO : {
                std::string scenarioNameToken = codeLine[1];
                currentScenario = scenarioNameToken;
                scenarioManager->CreateScenario(scenarioNameToken);
                break;
            }
            case VANILLA_ACTION::SCRIPT : {
                std::string scriptParameterToken = codeLine[1];
                if(scriptParameterToken != "END") {
                    currentScript = scriptParameterToken;
                } else if(currentScript != "") {
                        scenarioManager->CreateScript(currentScript, currentScenario, instructions);
                        instructions.clear();
                        instructionIndex = 1;
                        currentScript.clear();
                }
                break;
            }
            case VANILLA_ACTION::GO_TO : {
                std::string& scriptNameToken = codeLine[1];
                std::vector<std::string> arguments = { scriptNameToken };
                AddInstruction(INSTRUCTION_TYPE::GO_TO_SCRIPT, arguments);
                break;
            }
            case VANILLA_ACTION::CREATE : {
                std::string& createParameterToken = codeLine[1];
                std::vector<std::string> arguments;
                if(createParameterToken == "SCENE") {
                    std::string& sceneNameToken = codeLine[2];
                    arguments = { std::to_string((int)RESOURCE_TYPE::SCENE), sceneNameToken };
                } else if(createParameterToken == "ENTITY") {
                    std::string& entityNameToken = codeLine[2];
                    std::string& sceneNameToken = codeLine[3];
                    std::string transformTypeToken = codeLine[4];
                    if(transformTypeToken == "TRANSFORM_2D") {
                        transformTypeToken = std::to_string((int)ENTITY_TRANSFORM::TRANSFORM_2D);
                    } else if(transformTypeToken == "TRANSFORM_3D") {
                        transformTypeToken = std::to_string((int)ENTITY_TRANSFORM::TRANSFORM_3D);
                    }
                    std::string renderableTypeToken = codeLine[5];
                    if(renderableTypeToken == "NONE") {
                        renderableTypeToken = std::to_string((int)RENDERABLE_TYPE::NONE);
                    } else if(renderableTypeToken == "TEXTURE") {
                        renderableTypeToken = std::to_string((int)RENDERABLE_TYPE::TEXTURE);
                    } else if(renderableTypeToken == "TEXT") {
                        renderableTypeToken = std::to_string((int)RENDERABLE_TYPE::TEXT);
                    }
                    arguments = { std::to_string((int)RESOURCE_TYPE::ENTITY), entityNameToken, sceneNameToken, transformTypeToken, renderableTypeToken };
                } else if(createParameterToken == "TEXTURE") {
                    std::string& textureNameToken = codeLine[2];
                    std::string& texturePathToken = codeLine[3];
                    arguments = { std::to_string((int)RESOURCE_TYPE::TEXTURE), textureNameToken, texturePathToken };
                }
                if(!arguments.empty()) {
                    AddInstruction(INSTRUCTION_TYPE::CREATE_RESOURCE, arguments);
                }
                break;
            };
            case VANILLA_ACTION::START : {
                initScript = true;
                currentScript = "DUALTONES_INIT";
                break;
            };
            case VANILLA_ACTION::END : {
                if(initScript) {
                    scenarioManager->CreateInitScript(currentScenario, instructions);
                }
                break;
            };
            default:
                break;
        }
    }
}

void VanillaInterpreter::AddInstruction(INSTRUCTION_TYPE instructionType, std::vector<std::string> arguments) {
    Instruction* instruction = scenarioManager->CreateInstruction(instructionType, arguments, currentScenario + "/" + currentScript  + "/" + std::to_string(instructionIndex));
    instructions.push_back(instruction);
    instructionIndex++;
}