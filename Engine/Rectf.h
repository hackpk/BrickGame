#pragma once

#include "Vec2.h"


class Rectf
{
public:
	Rectf() = default;
	Rectf(float in_left, float in_right, float in_top, float in_bottom);
	Rectf(const Vec2& topLeft, const Vec2& bottomRight);
	Rectf(const Vec2& topLeft, float width, float height);
	bool IsOverlaping(const Rectf& rect);
	static Rectf FromCenter(const Vec2& center ,float halfWidth,float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};