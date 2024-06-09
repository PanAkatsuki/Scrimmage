#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2(int x, int y);
private:
	
public:
	int x;
	int y;
public:
	void Init();
	int Length() const;
	Vector2 Normalize() const;

	Vector2 V2PlusVec(Vector2& vec);
	void PlusVec(Vector2& vec);
	Vector2 V2MinusVec(Vector2& vec);
	void MinusVec(Vector2& vec);
	Vector2 V2MultiVal(int& val);
	int SumMultiVec(Vector2& vec);
	void MultiVal(int& val);
};