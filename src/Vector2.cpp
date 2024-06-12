#include "Vector2.h"

Vector2::Vector2(int x, int y)
	: x(x), y(y)
{

}

int Vector2::Length() const
{
	return (int)sqrt(x * x + y * y);
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