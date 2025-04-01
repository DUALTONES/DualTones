#include "entityComponents.h"

void RenderableComponent::SetPivotPoint(Vector2 pivotPoint) {
    renderable2D->pivotPoint = pivotPoint;
    renderable2D->CalculateOffset();
}

void RenderableComponent::SetTexture(Texture2D *texture) {
    renderable2D->texture = texture;
    renderable2D->CalculateDimensions();
}

void TextAttributeComponent::SetText(std::string text) {
    textAttributes->text = text;
}

void TextAttributeComponent::SetFont(Font *font) {
    textAttributes->font = font;
}

void TextAttributeComponent::SetFontSize(float fontSize) {
    textAttributes->fontSize = fontSize;
}

void TextAttributeComponent::SetSpacing(float spacing) {
    textAttributes->spacing = spacing;
}

void TextAttributeComponent::SetFill(bool hasFill) {
    textAttributes->hasFill = hasFill;
}

void TextAttributeComponent::SetTextColor(Color *textColor) {
    textAttributes->textColor = textColor;
}

void TextAttributeComponent::SetFillColor(Color *fillColor) {
    textAttributes->fillColor = fillColor;
}

void TextAttributeComponent::SetOutlineColor(Color *outineColor) {
    textAttributes->outlineColor = outineColor;
}
