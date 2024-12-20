#pragma once
#include "resourceManager.h"

enum class DYNAMIC_DATA_TYPE
{
    DISPLAY_MANAGER,
    RENDER_MANAGER,
    COUNT
};

class EngineCore
{
public:
    EngineCore();
    void HandleInput();
    void HandleEvents();
    void Draw();
private:
    void GetStaticData();
    void GetDynamicData();
    void UpdateDynamicDataList(DYNAMIC_DATA_TYPE type, std::string name);
    ResourceManager resourceManager;
    DisplayManager* displayManager;
    PreRenderManager* preRenderManager;
    RenderManager* renderManager;
    std::string dynamicDataList[int(DYNAMIC_DATA_TYPE::COUNT)];
};