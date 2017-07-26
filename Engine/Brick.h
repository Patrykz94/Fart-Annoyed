#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include "Beveler.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx);
	bool CheckBallCollisions(Ball& ball) const;
	void ExecuteBallCollisions(Ball& ball);
	Vec2 GetCenter() const;
	bool IsDestroyed() const;
private:
	RectF rect;
	Color color;
	Beveler bevel;
	bool destroyed = false;
	static constexpr float padding = 0.5f;
	static constexpr int bevelSize = 3;
};