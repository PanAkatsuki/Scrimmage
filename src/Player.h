#pragma once

#include <graphics.h>

#include "Vector2.h"
#include "Animation.h"
#include "Camera.h"
#include "Platform.h"

#include "Player_id.h"

extern std::vector<Platform> platform_list;

class Player
{
public:
	Player()
	{
		current_animation = &animation_idel_left;
	}
	~Player() = default;
private:
	bool is_left_key_down = false;
	bool is_right_key_down = false;
	bool is_up_key_down = false;

	bool is_facing_right = true;
	bool is_standing = false;
	bool is_double_jump = false;

	Animation* current_animation = nullptr;
protected:
	int gravity = 1;
	int run_speed = 5;
	int jump_speed = -20;

	PlayerID id = PlayerID::P1;
	Vector2 size = { 0, 0 };
	Vector2 position = { 0, 0 };
protected:
	// Update
	Vector2 velocity = { 0, 0 };
protected:

	Animation animation_idel_left;
	Animation animation_idel_right;
	Animation animation_run_left;
	Animation animation_run_right;
public:
	virtual void Input(ExMessage& msg);
	virtual void Update(int delta);
	virtual void Draw(Camera& camera);
public:
	// Set
	void SetID(PlayerID id);
	void SetSize(int x, int y);
	void SetPosition(int x, int y);
	void SetVelocity(int x, int y);
	// Get
	PlayerID GetId() const;
	Vector2 GetSize() const;
	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
public:
	virtual void run(int delta);
	virtual void jump(int delta);
	virtual void Gravity(int delta);
};