#pragma once

#include <graphics.h>

#include <functional>

#include "vector2.h"
#include "Camera.h"
#include "Player_id.h"

class Bullet
{
public:
	Bullet() = default;
	~Bullet() = default;
protected:
	Vector2 size = { 0, 0 };
	Vector2 position = { 0, 0 };
	Vector2 velocity = { 0, 0 };
	int damage = 0;
	bool valid = true;
	bool can_remove = false;
	PlayerID target_id = PlayerID::P1;
	std::function<void()> callback = nullptr;
public:
	void SetSize(Vector2& vec);
	Vector2 GetSize() const;
	void SetPosition(Vector2& vec);
	Vector2 GetPosition() const;
	void SetVelocity(Vector2& vec);
	Vector2 GetVelocity() const;
	void SetDamage(int val);
	int GetDamage() const;
	void SetValid(bool flag);
	bool GetValid() const;
	void SetCanRemove(bool flag);
	bool GetCanRemove() const;
	void SetTargetID(PlayerID id);
	PlayerID GetTargetID() const;
	void SetCallback(std::function<void()> callback);
public:
	void Update(int delta);
	void Draw(Camera& camera);
public:
	bool CheckBulletExceedsScreen();
public:
	virtual void Collide() const;
	virtual bool CheckCollision(Vector2& position, Vector2& size) const;

};