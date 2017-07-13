#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx);
private:
	RectF rect;
	Color color;
};