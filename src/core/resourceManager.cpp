#include "resourceManager.h"

ResourceManager::ResourceManager(MessagePool* messagePool, Renderable2DStack* renderable2DStack, TextureStack *textureStack, FontStack *fontStack, Composer* composer)
{
    this->messagePool = messagePool;
    this->renderable2DStack = renderable2DStack;
    this->textureStack = textureStack;
    this->fontStack = fontStack;
    this->composer = composer;
    fallbackTexture = LoadTexture("../assets/funnysneko/img/fallback.png");
    textureStack->AddTexture("FALLBACK", fallbackTexture);
    CreateScene("GUI");
    CreateScene("DEBUG");
}

void ResourceManager::LoadTextureToStack(std::string name, std::string path)
{
    Texture2D texture;
    bool success = true;
    if(FileExists(path.c_str()))
    {

        texture = LoadTexture(path.c_str());
    }
    else
    {
        success = false;
        texture = fallbackTexture;
        messagePool->AddMessage("[ RESOURCES ] FAILED TO LOAD TEXTURE FROM |-" + path + "-| BECAUSE FILE ISN'T FOUND");
    }
    textureStack->AddTexture(name, texture);
    if(success)
    {
        messagePool->AddMessage("[ RESOURCES ] CREATED TEXTURE |-" + name + "-|");
    }
    else
    {
        messagePool->AddMessage("[ RESOURCES ] CREATED TEXTURE |-" + name + "-| AS A DEFAULT TEXTURE");
    }
}

void ResourceManager::LoadFontToStack(std::string name, std::string path)
{
    Font font;
    if(FileExists(path.c_str()))
    {
        font = LoadFont(path.c_str());
        messagePool->AddMessage("[ RESOURCES ] LOADED FONT |-" + name + "-| FROM |-" + path + "-|");
    }
    else
    {
        messagePool->AddMessage("[ RESOURCES ] FAILED TO LOAD FONT |-" + name + "-| FROM |-" + path + "-| BECAUSE FILE ISN'T FOUND");
        font = GetFontDefault();
    }
    fontStack->AddFont(name, font);
}

void ResourceManager::CreateScene(std::string name)
{
    Scene scene;
    scenes.emplace(name, scene);
    messagePool->AddMessage("[ RESOURCES ] SCENE |-" + name + "-| IS CREATED");
}

Entity* ResourceManager::CreateEntity(std::string name, std::string sceneName, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE renderableType, PIVOT_POINT_2D pivotPoint)
{
    Scene* scene = GetScene(sceneName);
    if(scene != nullptr)
    {
        Entity entity;
        switch(entityTransform)
        {
            case ENTITY_TRANSFORM::TRANSFORM_2D:
            {
                entity.transformComponent = scene->AddTransform2DComponent(name);
                break;
            }
            case ENTITY_TRANSFORM::TRANSFORM_3D:
            {
                entity.transformComponent = scene->AddTransform3DComponent(name);
                break;
            }
        }
        switch(renderableType)
        {
            case RENDERABLE_TYPE::TEXTURE:
            case RENDERABLE_TYPE::TEXT:
            {
                entity.renderableComponent = scene->AddRenderableComponent(name, CreateRenderable2D(name, renderableType));
                Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(entity.renderableComponent->renderable);
                entity.renderableAttributesComponent = scene->AddRenderableAttributesComponent(name, renderable2D->renderable2DAtrributes);
                if(renderableType == RENDERABLE_TYPE::TEXT)
                {
                    entity.textAttributesComponent = scene->AddTextAttributesComponent(name, renderable2D->renderable2DAtrributes->textAttributes);
                }
                break;
            }
        }
        entity.renderableAttributesComponent->renderableAttributes->pivotPoint = pivotPoint;
        scene->AddEntity(name, entity);
        messagePool->AddMessage("[ RESOURCES ] CREATED ENTITY |-" + name + "-| IN THE SCENE |-" + sceneName + "-|");
        return scene->GetEntity(name);
    }
    else
    {
        messagePool->AddMessage("[ RESOURCES ] FAILED TO CREATE ENTITY |-" + name + "-| BECAUSE SCENE |-" + sceneName + "-| ISN'T FOUND");
        return nullptr;
    }
}

void ResourceManager::AddTextToEntity(std::string name, std::string sceneName, std::string text, std::string fontName, float fontSize, float spacing)
{
    Scene* scene = GetScene(sceneName);
    if(scene != nullptr)
    {
        Entity* entity = scene->GetEntity(name);
        if(entity != nullptr)
        {
            if(entity->renderableAttributesComponent->renderableAttributes->renderableType == RENDERABLE_TYPE::TEXT)
            {
                Font* font = fontStack->GetFont(fontName);
                if(font != nullptr)
                {
                    entity->textAttributesComponent->textAttributes->text = text;
                    entity->textAttributesComponent->textAttributes->font = font;
                    entity->textAttributesComponent->textAttributes->fontSize = fontSize;
                    entity->textAttributesComponent->textAttributes->spacing = spacing;
                    Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(entity->renderableComponent->renderable);
                    renderable2D->CalculateDimensions();
                    messagePool->AddMessage("[ RESOURCES ] ADDED TEXT TO ENTITY");
                }
                else
                {

                }
            }
            else
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }
}

void ResourceManager::AddTextureToEntity(std::string name, std::string sceneName, std::string textureName)
{
    Scene* scene = GetScene(sceneName);
    if(scene != nullptr)
    {
        Entity* entity = scene->GetEntity(name);
        if(entity != nullptr)
        {
            if(entity->renderableAttributesComponent->renderableAttributes->renderableType == RENDERABLE_TYPE::TEXTURE)
            {
                Texture2D* texture = textureStack->GetTexture(textureName);
                if(texture != nullptr)
                {
                    entity->renderableAttributesComponent->renderableAttributes->texture = texture;
                    Renderable2D* renderable2D = dynamic_cast<Renderable2D*>(entity->renderableComponent->renderable);
                    renderable2D->CalculateDimensions();
                }
                else
                {
                    messagePool->AddMessage("[ RESOURCES ] NO TEXTURE");
                }
            }
            else
            {
                messagePool->AddMessage("[ RESOURCES ] NO ATTRIBUTES");
            }
        }
        else
        {
            messagePool->AddMessage("[ RESOURCES ] NO ENTITY");
        }
    }
    else
    {
        messagePool->AddMessage("[ RESOURCES ] NO SCENE");
    }
}

Renderable2D* ResourceManager::CreateRenderable2D(std::string name, RENDERABLE_TYPE renderableType)
{
    renderable2DStack->AddRenderable2D(name, renderableType);
    return renderable2DStack->GetRenderable2D(name);
}

void ResourceManager::SetScene(std::string name)
{
    std::vector<Scene*> activeScenes;
    Scene* scene = GetScene(name);
    if(scene != nullptr)
    {
        activeScenes.push_back(scene);
        activeScenes.push_back(GetScene("GUI"));
        activeScenes.push_back(GetScene("DEBUG"));
        composer->SetScenes(activeScenes);
        messagePool->AddMessage("[ RESOURCES ] SET ACTIVE SCENE |-" + name + "-|");
    }
    else
    {
        messagePool->AddMessage("[ RESOURCES ] FAILED TO SET ACTIVE SCENE |-" + name + "-| BECAUSE SCENE ISN'T FOUND");
    }
}

Scene *ResourceManager::GetScene(std::string name)
{
    if(scenes.find(name) == scenes.end())
    {
        return nullptr;
    }
    return &scenes[name];
}