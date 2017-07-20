/**************************************************************
	A general rectangle function that will be used by other
	objects.
**************************************************************/
#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(Vec2& topLeft, Vec2& bottomRight);
	RectF(Vec2& topLeft, float width, float height);
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	bool IsOverlappingWith(const RectF& other) const;
	RectF GetExpanded(float offset) const;
	Vec2 GetCenter() const;
	Vec2 GetTopLeft() const;
public:
	float left;
	float right;
	float top;
	float bottom;
};