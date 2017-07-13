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
	bool IsOverlappingWith(const RectF& other) const;

public:
	float left;
	float right;
	float top;
	float bottom;
};