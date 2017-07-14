#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(Vec2& pos_in);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd, float dt);
	bool DoBallCollisions(Ball& ball);
	void DoWallCollisions(RectF& walls);
	RectF GetRect();
private:
	const Color color = Colors::White;
	const float speed = 300.0f;
	Vec2 pos;
	const float halfWidth = 50.0f;
	const float halfHeight = 15.0f;
	const float wingsWidth = 15.0f;
	const Color wingsColor = Colors::Red;
	bool isCooldown = false;
};