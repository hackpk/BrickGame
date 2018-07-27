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
	void DrawBrick( Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
private:
	Rectf rect;
	Color color;
	bool destroyed = false;
};