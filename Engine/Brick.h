#pragma once

#include "Rectf.h"
#include "Graphics.h"
#include "Colors.h"
#include "Ball.h"


class Brick
{
public :
	Brick() = default;
	Brick(const Rectf& in_rect,Color in_c);
	void DrawBrick( Graphics& gfx);
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter();
private:
	static constexpr float padding = 1.0f;
	Rectf rect;
	Color color;
	bool destroyed = false;
};