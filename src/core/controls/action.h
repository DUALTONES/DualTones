#pragma once

#include <string>
#include "../resource.h"

enum class ACTION_TYPE {
    LOAD_TEXTURE,
    LOAD_FONT,
    CREATE_SCENE,
};

class Action {
public:
    ACTION_TYPE actionType;
    virtual ~Action() = default;
};

class ActionLoadTexture : public Action {
public:
    ActionLoadTexture(std::string textureName, std::string path);
    std::string textureName;
    std::string path;
};

class ActionCreateScene : public Action {
public:
    ActionCreateScene(std::string sceneName);
    std::string sceneName;
};

class ActionCreateEntity : public Action {
public:
    std::string entityName;
    std::string sceneName;
    ENTITY_TRANSFORM entityTransform;
    RENDERABLE_TYPE entityRenderable;
};