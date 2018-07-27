#include "Paddle.h"

Paddle::Paddle(const Vec2& in_pos, float in_halfWidth, float in_halfHeight)
	:
	pos(in_pos),
	halfWidth(in_halfWidth),
	halfHeight(in_halfHeight)
{
}

void Paddle::DrawPaddle(Graphics & gfx)
{
	Rectf rect = GetRect();
	gfx.DrawRect(rect, colorExtra);
	{
		rect.left += Paddle::widthExtra;
		rect.right -= Paddle::widthExtra;
		gfx.DrawRect(rect, c);
	}
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	if (ball.GetVelocity().y > 0.0f &&GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const Rectf & walls)
{
	const Rectf rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Update(const Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

Rectf Paddle::GetRect() const
{
	return Rectf::FromCenter(pos,halfWidth,halfHeight);
}
