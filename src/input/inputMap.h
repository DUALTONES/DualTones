#pragma once
#include <string>
#include <unordered_map>

class KeyBind
{
public:
    int key;
    bool isHoldable;
    bool isHeld;
    int pressEvent = 0;
    int holdEvent = 0;
    int unpressEvent = 0;
    KeyBind* combinationKey;
};

class InputMap
{
public:
    std::unordered_map<int, KeyBind> inputMap;
};