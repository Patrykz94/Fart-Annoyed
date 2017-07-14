#include "Brick.h"

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

bool Brick::DoBallCollisions(Ball & ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		destroyed = true;
		ball.ReboundY();
		return true;
	}
	return false;
}
