#pragma once

#include <graphics.h>

#include <functional>

#include "Camera.h"
#include "Player_id.h"

class Bullet
{
public:
	Bullet() = default;
	~Bullet() = default;
protected:
	PlayerID target_id = PlayerID::P1;
	Vector2 size = { 0, 0 };
	Vector2 position = { 0, 0 };
	Vector2 velocity = { 0, 0 };
	int damage = 0;
	bool valid = true;
	bool can_remove = false;
	std::function<void()> callback = nullptr;
public:
	// Set
	void SetTargetID(PlayerID id);
	void SetSize(Vector2& vec);
	void SetPosition(Vector2& vec);
	void SetVelocity(Vector2& vec);
	void SetDamage(int val);
	void SetValid(bool flag);
	void SetCanRemove(bool flag);
	void SetCallback(std::function<void()> callback);

	// Get
	PlayerID GetTargetID() const;
	Vector2 GetSize() const;
	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
	int GetDamage() const;
	bool GetValid() const;
	bool GetCanRemove() const;
public:
	// Default
	virtual void Update(int& delta);
	virtual void Draw(Camera& camera) const;
public:
	// Check
	bool CheckBulletExceedsScreen();
public:
	// Collide
	virtual void Collide() const;
	virtual bool CheckCollision(Vector2& position, Vector2& size) const;

};