#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
{
	left = left_in;
	right = right_in;
	top = top_in;
	bottom = bottom_in;
}

RectF::RectF(Vec2& topLeft, Vec2& bottomRight)
{
	RectF( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y);
}

RectF::RectF(Vec2& topLeft, float width, float height)
{
	RectF( topLeft, topLeft + Vec2( width, height ) );
}

bool RectF::IsOverlappingWith(RectF& other)
{
	if (left < other.right && right > other.left && top < other.bottom && bottom > other.top) {
		return true;
	}
	return false;
}
