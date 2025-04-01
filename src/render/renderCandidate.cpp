#include "renderCandidate.h"

RenderCandidate::RenderCandidate(Renderable2D *renderable2D, Vector2 absolutePosition, float absoluteScale) {
    this->renderable2D = renderable2D;
    this->absolutePosition = absolutePosition;
    this->absoluteScale = absoluteScale;
}