#include "engineCore.h"

EngineCore::EngineCore()
{
    UpdateDynamicDataList(DYNAMIC_DATA_TYPE::DISPLAY_MANAGER, "display");
    UpdateDynamicDataList(DYNAMIC_DATA_TYPE::RENDER_MANAGER, "render");
    GetStaticData();
    GetDynamicData();
}

void EngineCore::HandleInput()
{
    
}

void EngineCore::HandleEvents()
{

}

void EngineCore::Draw()
{
    displayManager->Update();
    //preRenderManager->Update();
    renderManager->Update();
}

void EngineCore::GetStaticData()
{
    preRenderManager = resourceManager.GetPreRenderManager();
}

void EngineCore::GetDynamicData()
{
    displayManager = dynamic_cast<DisplayManager*>(resourceManager.GetManager(dynamicDataList[int(DYNAMIC_DATA_TYPE::DISPLAY_MANAGER)]));
    renderManager = dynamic_cast<RenderManager*>(resourceManager.GetManager(dynamicDataList[int(DYNAMIC_DATA_TYPE::RENDER_MANAGER)]));
}

void EngineCore::UpdateDynamicDataList(DYNAMIC_DATA_TYPE type, std::string name)
{
    dynamicDataList[int(type)] = name;
}