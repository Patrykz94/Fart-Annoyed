#include "Paddle.h"

Paddle::Paddle(Vec2 & pos_in)
	:
	pos(pos_in)
{
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetRect(), wingsColor);
	RectF inRect = GetRect();
	inRect.left += wingsWidth;
	inRect.right -= wingsWidth;
	gfx.DrawRect(inRect, color);
}

void Paddle::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
}

bool Paddle::DoBallCollisions(Ball & ball)
{
	if (GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollisions(RectF & walls)
{
	if (GetRect().left < walls.left)
	{
		pos.x += walls.left - GetRect().left;
	}
	else if (GetRect().right > walls.right)
	{
		pos.x -= GetRect().right - walls.right;
	}
}

RectF Paddle::GetRect()
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
