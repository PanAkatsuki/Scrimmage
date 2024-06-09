#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::~Vector2()
{

}
Vector2::Vector2(float x, float y)
	: x(x), y(y)
{

}

void Vector2::Init()
{
	x = 0;
	y = 0;
}
float Vector2::Length() const
{
	return sqrt(x * x + y * y);
}
Vector2 Vector2::Normalize() const
{
	float len = Length();

	if (len == 0)
	{
		return Vector2(0, 0);
	}

	return Vector2(x / len, y / len);
}
Vector2 Vector2::V2PlusVec(Vector2& vec)
{
	return Vector2(x + vec.x, y + vec.y);
}
void Vector2::PlusVec(Vector2& vec)
{
	x += vec.x;
	y += vec.y;
}
Vector2 Vector2::V2MinusVec(Vector2& vec)
{
	return Vector2(x - vec.x, y - vec.y);
}
void Vector2::MinusVec(Vector2& vec)
{
	x -= vec.x;
	y -= vec.y;
}
Vector2 Vector2::V2MultiVal(float& val)
{
	return Vector2(x * val, y * val);
}
float Vector2::SumMultiVec(Vector2& vec)
{
	return x * vec.x + y * vec.y;
}
void Vector2::MultiVal(float& val)
{
	x *= val;
	y *= val;
}