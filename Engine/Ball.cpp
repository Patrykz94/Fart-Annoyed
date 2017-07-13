#include "Ball.h"

Ball::Ball(Vec2 & pos_in, Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

RectF Ball::GetRect()
{
	return RectF::FromCenter(pos, radius, radius);
}

bool Ball::DoWallCollisons(RectF & walls)
{
	bool collided = false;

	if (GetRect().left < walls.left)
	{
		pos.x += walls.left - GetRect().left;
		ReboundX();
		collided = true;
	}
	else if (GetRect().right > walls.right)
	{
		pos.x -= GetRect().right - walls.right;
		ReboundX();
		collided = true;
	}
	if (GetRect().top < walls.top)
	{
		pos.y += walls.top - GetRect().top;
		ReboundY();
		collided = true;
	}
	else if (GetRect().bottom > walls.bottom)
	{
		pos.y -= GetRect().bottom - walls.bottom;
		ReboundY();
		collided = true;
	}

	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}
