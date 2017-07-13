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
	brick(RectF(Vec2(200.0f, 150.0f), 50.0f, 30.0f), Colors::Green),
	ball(Vec2(200.0f, 200.0f), Vec2(300.0f, 300.0f)),
	pad(Vec2(gfx.ScreenWidth/2, gfx.ScreenHeight - 100)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{
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
	if (brick.DoBallCollisions(ball))
	{
		soundBrick.Play();
	}
}

void Game::ComposeFrame()
{
	brick.Draw(gfx);
	pad.Draw(gfx);
	ball.Draw(gfx);
}
