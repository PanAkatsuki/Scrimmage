#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::~Vector2()
{

}
Vector2::Vector2(int x, int y)
	: x(x), y(y)
{

}

void Vector2::Init()
{
	x = 0;
	y = 0;
}
int Vector2::Length() const
{
	return sqrt(x * x + y * y);
}
Vector2 Vector2::Normalize() const
{
	int len = Length();

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
Vector2 Vector2::V2MultiVal(int& val)
{
	return Vector2(x * val, y * val);
}
int Vector2::SumMultiVec(Vector2& vec)
{
	return x * vec.x + y * vec.y;
}
void Vector2::MultiVal(int& val)
{
	x *= val;
	y *= val;
}