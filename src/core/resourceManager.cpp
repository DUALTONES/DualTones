#include "resourceManager.h"

Resource *ResourceStack::AddResource(std::string name, Resource *resource) {
    stack[name] = resource;
    return stack[name];
}

Resource *ResourceStack::CreateResource(std::string name, RESOURCE_TYPE resourceType) {
    Resource* resource = GetResource(name, resourceType);
    if(resource != nullptr) {
        RemoveResource(name, resourceType);
    }

    switch (resourceType) {
        case RESOURCE_TYPE::SCENARIO : {
            Scenario* scenario = new Scenario();
            resource = dynamic_cast<Resource*>(scenario);
            break;
        }
        case RESOURCE_TYPE::INSTRUCTION: {
            resource = new Instruction();
            break;
        }
        case RESOURCE_TYPE::SCRIPT : {
            resource = new Script();
            break;
        }
        case RESOURCE_TYPE::TEXTURE : {
            resource = new TextureResource();
            break;
        }
        case RESOURCE_TYPE::FONT : {
            resource = new FontResource();
            break;
        }
        case RESOURCE_TYPE::COLOR : {
            resource = new ColorResource();
            break;
        }
        case RESOURCE_TYPE::SCENE : {
            resource = new Scene();
            break;
        }
        case RESOURCE_TYPE::ENTITY : {
            resource = new Entity();
            break;
        }
        case RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_2D : {
            resource = new Transform2DComponent();
            break;
        }
        case RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_3D : {
            resource = new Transform3DComponent();
            break;
        }
        case RESOURCE_TYPE::ENTITY_COMPONENT_RENDERABLE : {
            resource = new RenderableComponent();
            break;
        }
        case RESOURCE_TYPE::ENTITY_COMPONENT_TEXT_ATTRIBUTES : {
            resource = new TextAttributeComponent();
            break;
        }
        case RESOURCE_TYPE::RENDERABLE_2D : {
            resource = new Renderable2D();
            break;
        }
        case RESOURCE_TYPE::TEXT_ATTRIBUTES : {
            resource = new TextAttributes();
            break;
        }
        default: {
            break;
        }
    }

    resource->name = name;
    resource->type = resourceType;
    return AddResource(name + std::to_string(int(resourceType)), resource);
}

Resource *ResourceStack::GetResource(std::string name, RESOURCE_TYPE resourceType) {
    if(stack.find(name + std::to_string(int(resourceType))) != stack.end()) {
        return stack[name + std::to_string(int(resourceType))];
    }
    return nullptr;
}

void ResourceStack::RemoveResource(std::string name, RESOURCE_TYPE resourceType) {
    if(stack.find(name + std::to_string(int(resourceType))) != stack.end()) {
        std::cout << "DELETING " << RESOURCE_TYPE_NAMES[(int)resourceType] << " " << name << std::endl;
        delete stack[name + std::to_string(int(resourceType))];
        stack.erase(name + std::to_string(int(resourceType)));
    }
}

void ResourceStack::DisplayContent() {
    std::cout << "\n[ RESOURCE STACK CONTENT ]\n" << std::endl;
    int index = 1;
    for(std::pair<std::string, Resource*> pair : stack) {
        std::cout << index << ": " << " |-" << pair.second->name << "-| [ " << pair.first << " ] " << RESOURCE_TYPE_NAMES[(int)pair.second->type] << std::endl;
        index++;
    }
}

void ResourceManager::Display() {
    resourceStack.DisplayContent();
}

Scenario *ResourceManager::CreateScenario(std::string name)
{
    return dynamic_cast<Scenario*>(resourceStack.CreateResource(name, RESOURCE_TYPE::SCENARIO));
}

Instruction *ResourceManager::CreateInstruction(std::string name) {
    return dynamic_cast<Instruction*>(resourceStack.CreateResource(name, RESOURCE_TYPE::INSTRUCTION));
}

Script *ResourceManager::CreateScript(std::string name) {
    return dynamic_cast<Script*>(resourceStack.CreateResource(name, RESOURCE_TYPE::SCRIPT));
}

Texture2D *ResourceManager::LoadTextureToStack(std::string name, std::string path)
{
    TextureResource* textureResource;

    if(FileExists(path.c_str())) {
        Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::TEXTURE);
        if(resource == nullptr) {
            resource = resourceStack.CreateResource(name, RESOURCE_TYPE::TEXTURE);
        }
        textureResource = dynamic_cast<TextureResource*>(resource);
        textureResource->texture = LoadTexture(path.c_str());
    } else {
        textureResource = dynamic_cast<TextureResource*>(resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::TEXTURE));
    }

    return &textureResource->texture;
}

Font *ResourceManager::LoadFontToStack(std::string name, std::string path){
    FontResource* fontResource;

    if(FileExists(path.c_str())) {
        Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::FONT);
        if(resource == nullptr) {
            resource = resourceStack.CreateResource(name, RESOURCE_TYPE::FONT);
        }
        fontResource = dynamic_cast<FontResource*>(resource);
        fontResource->font = LoadFont(path.c_str());
    } else {
        fontResource = dynamic_cast<FontResource*>(resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::FONT));
    }

    return &fontResource->font;
}

Color *ResourceManager::CreateColorOnStack(std::string name, Vector4 RGBA) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::COLOR);
    if(resource == nullptr) {
        resource = resourceStack.CreateResource(name, RESOURCE_TYPE::COLOR);
    }
    ColorResource* colorResource = dynamic_cast<ColorResource*>(resource);
    colorResource->color = {0, 0, 0, 0};

    return &colorResource->color;
}

Scene *ResourceManager::CreateScene(std::string name) {
    return dynamic_cast<Scene*>(resourceStack.CreateResource(name, RESOURCE_TYPE::SCENE));
}

Entity *ResourceManager::CreateEntity(std::string name, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::ENTITY);
    if(resource != nullptr) {
        Entity* entity = dynamic_cast<Entity*>(resource);
        DeleteEntity(name, entity->transform, entity->renderableType);
    }
    resource = resourceStack.CreateResource(name, RESOURCE_TYPE::ENTITY);
    Entity* entity = dynamic_cast<Entity*>(resource);

    if(entityTransform == ENTITY_TRANSFORM::TRANSFORM_2D) {
        entity->transform2DComponent = dynamic_cast<Transform2DComponent*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_2D
        ));
    } else if(entityTransform == ENTITY_TRANSFORM::TRANSFORM_3D) {
        entity->transform3DComponent = dynamic_cast<Transform3DComponent*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_3D
        ));
    }
    entity->transform = entityTransform;

    if(entityRenderable != RENDERABLE_TYPE::NONE) {
        entity->renderableComponent = dynamic_cast<RenderableComponent*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::ENTITY_COMPONENT_RENDERABLE
        ));
        entity->renderableComponent->renderable2D = dynamic_cast<Renderable2D*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::RENDERABLE_2D
        ));
    }
    if(entityRenderable == RENDERABLE_TYPE::TEXT) {
        entity->textAttributeComponent = dynamic_cast<TextAttributeComponent*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::ENTITY_COMPONENT_TEXT_ATTRIBUTES
        ));
        entity->textAttributeComponent->textAttributes = dynamic_cast<TextAttributes*>(resourceStack.CreateResource(
            name,
            RESOURCE_TYPE::TEXT_ATTRIBUTES
        ));
        entity->renderableComponent->renderable2D->textAttributes = entity->textAttributeComponent->textAttributes;
    }
    entity->renderableType = entityRenderable;

    return entity;
}

Texture2D *ResourceManager::GetTexture(std::string name) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::TEXTURE);
    if (resource == nullptr) {
        resource = resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::TEXTURE);
    }
    TextureResource* textureResource = dynamic_cast<TextureResource*>(resource);
    return &textureResource->texture;
}

Font *ResourceManager::GetFont(std::string name) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::FONT);
    if (resource == nullptr) {
        resource = resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::FONT);
    }
    FontResource* fontResource = dynamic_cast<FontResource*>(resource);
    return &fontResource->font;
}

Color *ResourceManager::GetColor(std::string name) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::FONT);
    if (resource == nullptr) {
        resource = resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::COLOR);
    }
    ColorResource* colorResource = dynamic_cast<ColorResource*>(resource);
    return &colorResource->color;
}

Scene *ResourceManager::GetScene(std::string name) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::SCENE);
    if(resource == nullptr) {
        resource = resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::SCENE);
    }
    Scene* scene = dynamic_cast<Scene*>(resource);
    return scene;
}

Entity *ResourceManager::GetEntity(std::string name) {
    Resource* resource = resourceStack.GetResource(name, RESOURCE_TYPE::ENTITY);
    if(resource == nullptr) {
        resource = resourceStack.GetResource("DUALTONES_FALLBACK", RESOURCE_TYPE::ENTITY);
    }
    Entity* entity = dynamic_cast<Entity*>(resource);
    return entity;
}

void ResourceManager::DeleteResource(std::string name, RESOURCE_TYPE resourceType) {
    resourceStack.RemoveResource(name, resourceType);
}

void ResourceManager::DeleteEntity(std::string name, ENTITY_TRANSFORM entityTransform, RENDERABLE_TYPE entityRenderable)
{
    if(entityTransform == ENTITY_TRANSFORM::TRANSFORM_2D) {
        resourceStack.RemoveResource(name, RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_2D);
    } else if(entityTransform == ENTITY_TRANSFORM::TRANSFORM_3D) {
        resourceStack.RemoveResource(name, RESOURCE_TYPE::ENTITY_COMPONENT_TRANSFORM_3D);
    }
    if(entityRenderable != RENDERABLE_TYPE::NONE) {
        resourceStack.RemoveResource(name, RESOURCE_TYPE::ENTITY_COMPONENT_RENDERABLE);
        resourceStack.RemoveResource(name, RESOURCE_TYPE::RENDERABLE_2D);
    }
    if(entityRenderable == RENDERABLE_TYPE::TEXT) {
        resourceStack.RemoveResource(name, RESOURCE_TYPE::ENTITY_COMPONENT_TEXT_ATTRIBUTES);
        resourceStack.RemoveResource(name, RESOURCE_TYPE::TEXT_ATTRIBUTES);
    }
    resourceStack.RemoveResource(name, RESOURCE_TYPE::ENTITY);
}