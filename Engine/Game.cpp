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
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	ball(Vec2(gfx.ScreenWidth/2, 200.0f), Vec2(0.0f, 200.0f)),
	pad(Vec2(gfx.ScreenWidth/2, gfx.ScreenHeight - 100)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{
	Color c[4] = { Colors::Blue, Colors::Green, Colors::Red, Colors::Yellow };

	int i = 0;
	for (int y = 0; y < verticalBricks; y++)
	{
		for (int x = 0; x < horizontalBricks; x++)
		{
			bricks[i] = Brick(RectF(topPos + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight), c[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt)
{
	ball.Update(dt);

	bool collisionHappened = false;
	float curColDistSq;
	int curColIndex;
	for (int i = 0; i < nBricks; i++)
	{
		if (bricks[i].CheckBallCollisions(ball))
		{
			const float newColDistSq = (ball.GetPosition() - bricks[i].GetCenter()).GetLengthSq();
			if (collisionHappened) {
				if (newColDistSq < curColDistSq)
				{
					curColDistSq = newColDistSq;
					curColIndex = i;
				}
			}
			else
			{
				curColDistSq = newColDistSq;
				curColIndex = i;
				collisionHappened = true;
			}
		}
	}
	if (collisionHappened) {
		bricks[curColIndex].ExecuteBallCollisions(ball);
		soundBrick.Play();
	}

	pad.Update(wnd.kbd, dt);
	pad.DoWallCollisions(walls);
	if (pad.DoBallCollisions(ball))
	{
		soundPad.Play();
	}
	if (ball.DoWallCollisons(walls))
	{
		soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	for (Brick b : bricks)
	{
		b.Draw(gfx);
	}
	pad.Draw(gfx);
	ball.Draw(gfx);
}
