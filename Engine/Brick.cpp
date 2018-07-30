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
	if (std::signbit(ball.GetVelocity().x)==std::signbit(ballPos.x - GetCenter().x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter()
{
	return rect.GetCenter();
}
