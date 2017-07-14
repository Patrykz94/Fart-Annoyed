#include "Brick.h"
#include <assert.h>

Brick::Brick(RectF & rect_in, Color color_in)
	:
	rect(rect_in),
	color(color_in)
{
}

void Brick::Draw(Graphics & gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::CheckBallCollisions(Ball & ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollisions(Ball & ball)
{
	assert(CheckBallCollisions(ball));
	const Vec2 ballPos = ball.GetPosition();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
