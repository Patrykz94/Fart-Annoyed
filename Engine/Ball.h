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
	RectF GetRect();
	bool DoWallCollisons(RectF& walls);
	void ReboundX();
	void ReboundY();
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};