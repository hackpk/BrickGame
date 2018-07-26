#include "Brick.h"

Brick::Brick(const Rectf & in_rect, Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::DrawBrick(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}