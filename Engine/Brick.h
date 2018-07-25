#pragma once

#include "Rectf.h"
#include "Graphics.h"



class Brick
{
public :
	Brick() = default;
	Brick(const Rectf& in_rect,Color in_c);
	void DrawBrick( Graphics& gfx) const;
private:
	Rectf rect;
	Color color;
	bool destroyed = false;
};