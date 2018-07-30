#pragma once

#include "Rectf.h"
#include "Graphics.h"
#include "Ball.h"
#include "Vec2.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vec2& in_pos, float halfWidth, float halfHeight);
	void DrawPaddle(Graphics& gfx );
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const Rectf& walls);
	void Update(const Keyboard& kbd, float dt);
	Rectf GetRect()const;
	void ResetCoolDown();
private:
	static constexpr float widthExtra = 10.0f;
	static constexpr Color colorExtra = Colors::Blue;
	Color c = Colors::White;
	float speed = 200.0f;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
	bool isCoolDown = false;
};