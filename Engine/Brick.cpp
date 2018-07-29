#include "Brick.h"
#include "assert.h"

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

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return (!destroyed) && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPos();
	if (ballPos.x < rect.left && ballPos.x > rect.right)
	{
		ball.ReboundX();
	}
	else
	{
		ball.ReboundY();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter()
{
	return Vec2((rect.left + rect.right)/2.0f,(rect.top + rect.bottom)/2.0f);
}
