#include "Brick.h"

Brick::Brick(const Rectf & in_rect, Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::DrawBrick(Graphics& gfx)
{
	if (!destroyed)
	{ 
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::DoBallCollision(Ball & ball) 
{
	if ((!destroyed) && rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
