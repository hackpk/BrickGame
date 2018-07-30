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

bool Paddle::DoBallCollision(Ball & ball)
{
	if (!isCoolDown)
	{
		const Rectf rect = GetRect();
		if (rect.IsOverlappingWith(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPos();
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x))
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
			isCoolDown = true;
			return true;
		}
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

void Paddle::ResetCoolDown()
{
	isCoolDown = false;
}

