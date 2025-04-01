#include "action.h"

ActionLoadTexture::ActionLoadTexture(std::string textureName, std::string path) {
    actionType = ACTION_TYPE::LOAD_TEXTURE;
    this->textureName = textureName;
    this->path = path;
}

ActionCreateScene::ActionCreateScene(std::string sceneName) {
    actionType = ACTION_TYPE::CREATE_SCENE;
    this->sceneName = sceneName;
}