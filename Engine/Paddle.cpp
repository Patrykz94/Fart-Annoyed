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
	const RectF rect = GetRect();
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		if (!isCooldown) {
			const Vec2 ballPos = ball.GetPosition();
			const Vec2 ballDir = pos - ballPos;
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x))
			{
				ball.ReboundPad(ballDir);
			}
			else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
			{
				ball.ReboundPad(ballDir);
			}
			else
			{
				ball.ReboundX();
			}
			isCooldown = true;
			return true;
		}
		return false;
	}
	isCooldown = false;
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

void Paddle::Reset(Vec2 & pos_in)
{
	pos = pos_in;
}
