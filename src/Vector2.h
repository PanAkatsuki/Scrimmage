#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2(float x, float y);
private:
	
public:
	float x;
	float y;
public:
	void Init();
	float Length() const;
	Vector2 Normalize() const;

	Vector2 V2PlusVec(Vector2& vec);
	void PlusVec(Vector2& vec);
	Vector2 V2MinusVec(Vector2& vec);
	void MinusVec(Vector2& vec);
	Vector2 V2MultiVal(float& val);
	float SumMultiVec(Vector2& vec);
	void MultiVal(float& val);
};