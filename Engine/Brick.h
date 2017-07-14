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
	bool CheckBallCollisions(Ball& ball) const;
	void ExecuteBallCollisions(Ball& ball);
	Vec2 GetCenter() const;
private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float padding = 2.0f;
};