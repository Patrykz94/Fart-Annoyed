#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx);
	bool DoBallCollisions(Ball& ball);
private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float padding = 2.0f;
};