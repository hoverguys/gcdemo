#include "Rect.h"

eastl::pair<Vector2D, Vector2D> Rect::Bounds() const {
	return eastl::pair<Vector2D, Vector2D>(start, start + size);
}

void Rect::Move(const Vector2D& delta) {
	start += delta;
}

void Rect::Resize(const Vector2D& _size) {
	size += _size;
}