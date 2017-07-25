#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(Vec2& pos_in, Vec2& vel_in);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool DoWallCollisons(RectF& walls);
	void ReboundPad(const Vec2& padDir);
	void ReboundX();
	void ReboundY();
	RectF GetRect();
	Vec2 GetVelocity();
	Vec2 GetPosition();
	bool HitBottomWall();
	void Reset(const Vec2& pos_in, const Vec2& vel_in);
	void StickToPad(const Vec2& padPos);
	void SpeedUp();

private:
	bool hitBottom = false;
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
};