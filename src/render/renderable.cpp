#include "renderable.h"

void Renderable2D::Draw(Vector2 absolutePosition, float absoluteScale) {
    switch(type) {
        case RENDERABLE_TYPE::TEXTURE: {
            DrawTextureEx(*texture, absolutePosition, 0.0f, absoluteScale, WHITE);
            break;
        }
        case RENDERABLE_TYPE::TEXT: {
            if(textAttributes->hasFill) {
                DrawRectangle(absolutePosition.x, absolutePosition.y, dimensions.x, dimensions.y, *textAttributes->fillColor);
            }
            DrawTextEx(
                *textAttributes->font,
                textAttributes->text.c_str(),
                absolutePosition,
                textAttributes->fontSize * absoluteScale,
                textAttributes->spacing * absoluteScale,
                *textAttributes->textColor
            );
            break;
        }
    }
}

void Renderable2D::CalculateDimensions() {
    switch(type) {
        case RENDERABLE_TYPE::TEXTURE: {
            dimensions = {(float)texture->width, (float)texture->height};
            break;
        }
        case RENDERABLE_TYPE::TEXT: {
            dimensions = MeasureTextEx(*textAttributes->font, textAttributes->text.c_str(), textAttributes->fontSize, textAttributes->spacing);
            break;
        }
    }
}

void Renderable2D::CalculateOffset() {
    halfDimensions = Vector2Scale(dimensions, 0.5f);
    pivotOffset = {
        halfDimensions.x * (-1) + halfDimensions.x * pivotPoint.x,
        halfDimensions.y * (-1) + halfDimensions.y * pivotPoint.y
    };
}