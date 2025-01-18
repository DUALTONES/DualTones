#include "resources.h"

void TextureStack::AddTexture(std::string name, Texture2D texture)
{
    stack.emplace(name, texture);
}

Texture2D* TextureStack::GetTexture(std::string name)
{
    return &stack[name];
}

void TextureStack::RemoveTexture(std::string name)
{
    stack.erase(name);
}

void FontStack::AddFont(std::string name, Font font)
{
    stack.emplace(name, font);
}

Font *FontStack::GetFont(std::string name)
{
    return &stack[name];
}

void FontStack::RemoveFont(std::string name)
{
    stack.erase(name);
}