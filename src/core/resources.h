#pragma once
#include <unordered_map>
#include <string>
#include "raylib/raylib.h"

class TextureStack
{
public:
    void AddTexture(std::string name, Texture2D texture);
    Texture2D* GetTexture(std::string name);
    void RemoveTexture(std::string name);
private:
    std::unordered_map<std::string, Texture2D> stack;
};

class FontStack
{
public:
    void AddFont(std::string name, Font font);
    Font* GetFont(std::string name);
    void RemoveFont(std::string name);
private:
    std::unordered_map<std::string, Font> stack;
};