#pragma once

#include "Vec2.h"


class Rectf
{
public:
	Rectf() = default;
	Rectf(float in_left, float in_right, float in_top, float in_bottom);
	Rectf(const Vec2& topLeft, const Vec2& bottomRight);
	Rectf(const Vec2& topLeft, float width, float height);
	bool IsOverlappingWith(const Rectf& rect) const;
	static Rectf FromCenter(const Vec2& center ,float halfWidth,float halfHeight);
	Rectf GetExpanded(const float offset);
public:
	float left;
	float right;
	float top;
	float bottom;
};