#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vec2& in_pos,Vec2& in_vel);
	void Draw( Graphics& gfx) const;
	void Update(float dt);
	bool IsColliding(const Rectf& walls);
	void ReboundX();
	void ReboundY();
	Rectf GetRect();
	
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};