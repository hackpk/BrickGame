#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 & in_pos, Vec2 & in_vel)
{
	pos = in_pos;
	vel = in_vel;
}

void Ball::Draw( Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::IsColliding(const Rectf & walls)
{
	bool collided = false;
    const Rectf rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right-walls.right;
		ReboundX();
		collided = true;
	}
	else if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom-walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}


void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

Rectf Ball::GetRect()
{
	return Rectf::FromCeter(pos,radius,radius);
}




