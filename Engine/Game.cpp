/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.0f,300.0f),Vec2(300.0f,300.0f)),
	walls(0.0f,float(gfx.ScreenWidth),0.0f,float(gfx.ScreenHeight)),
	pad(Vec2(400.0f,500.0f),50.0f,13.0f)
{
	const Color colors[5] = { Colors::Red,Colors::Blue,Colors::Gray,Colors::Yellow,Colors::Green };

	Vec2 topLeft = { 0.0f,0.0f };
	int i = 0;
	for (int y = 0; y < nBricksDown; y++)
	{
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++)
		{
			brick[i] = Brick(Rectf(topLeft+Vec2(float(x*brickWidth),float(y*brickHeight)),brickWidth,brickHeight),c);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update(dt);

	pad.Update(wnd.kbd,dt);
	pad.DoWallCollision(walls);

	for (Brick& b : brick)
	{
		if (b.DoBallCollision(ball))
		{

		}
	}
	if (pad.DoBallCollision(ball))
	{

	}

	if (ball.IsColliding(walls))
	{

	}
}
void Game::ComposeFrame()
{
	ball.Draw(gfx);
	for (Brick& b : brick)
	{
		b.DrawBrick(gfx);
	}

	pad.DrawPaddle(gfx);
}

