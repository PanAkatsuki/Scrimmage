#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2() = default;
	~Vector2() = default;
	Vector2(int x, int y);
private:
	
public:
	int x = 0;
	int y = 0;
public:
	int Length() const;
	Vector2 Normalize() const;
};