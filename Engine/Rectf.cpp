#include "Rectf.h"

Rectf::Rectf(float in_left, float in_right, float in_top, float in_bottom)
	:
	left(in_left),
	right(in_right),
	top(in_top),
	bottom(in_bottom)
{
}

Rectf::Rectf(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	Rectf(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

Rectf::Rectf(const Vec2 & topLeft, float width, float height)
	:
	Rectf(topLeft, topLeft + Vec2(width, height))
{
}


bool Rectf::IsOverlappingWith(const Rectf & other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

Rectf Rectf::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return Rectf(center - half,center + half);
}

Rectf Rectf::GetExpanded(const float offset)
{
	return Rectf(left - offset,right + offset,top - offset, bottom  + offset);
}
