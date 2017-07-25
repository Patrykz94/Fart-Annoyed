#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// drawing of a sprite
	static void DrawBall(const Vec2& center,Graphics& gfx);
	static void DrawDead(const Vec2& center, Graphics& gfx);
	static void DrawTitle(const Vec2& center, Graphics& gfx);
	static void DrawGameOver(const Vec2& center, Graphics& gfx);
	static void DrawHeart(const Vec2& topLeft, Graphics& gfx);
	static void DrawTextScore(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumberScore(const Vec2& topLeft, Graphics& gfx, const int& score);

	// drawing number sprites 14px x 14px
	static void DrawNumber0(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber1(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber2(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber3(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber4(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber5(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber6(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber7(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber8(const Vec2& topLeft, Graphics& gfx);
	static void DrawNumber9(const Vec2& topLeft, Graphics& gfx);
};