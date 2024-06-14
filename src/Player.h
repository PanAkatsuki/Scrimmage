#pragma once

#include <graphics.h>

#include "Animation.h"
#include "Camera.h"
#include "Platform.h"
#include "Bullet.h"

#include "Player_id.h"

#include "SketchImage.h"

extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern Camera camera;

class Player
{
public:
	Player();
	~Player() = default;
protected:
	// Operate
	bool is_left_key_down = false;
	bool is_right_key_down = false;
	bool is_up_key_down = false;
	bool is_down_key_down = false;

	// Direction
	bool is_facing_right = true;

	// Jump
	bool is_standing = false;
	bool can_jump = true;
	bool can_double_jump = false;

	// Attack
	bool can_attack = true;
	int attack_cd = 30;
	Timer timer_attack_cd;

	// Attack ex
	bool is_attack_ex = false;

	// Invulnerbale
	IMAGE img_sketch;
	bool is_invulnerable = false;
	bool is_showing_sketch_frame = false;
	Timer timer_invulnerable;
	Timer timer_invulnerable_blink;

	// Animation
	Animation* current_animation = nullptr;
protected:
	int gravity = 1;

	// Speed
	int run_speed = 5;
	int jump_speed = -20;

	int hp = 100;
	int mp = 0;

	PlayerID id = PlayerID::P1;
	Vector2 size = { 0, 0 };
	Vector2 position = { 0, 0 };
protected:
	// Update
	Vector2 velocity = { 0, 0 };
protected:
	// Animation
	Animation animation_idel_left;
	Animation animation_idel_right;
	Animation animation_run_left;
	Animation animation_run_right;
	Animation animation_attack_ex_left;
	Animation animation_attack_ex_right;
public:
	virtual void Input(ExMessage& msg);
	virtual void Update(int& delta);
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
	void Gravity(int delta); // is_standing
	void Run(int delta);
	void Jump();
	void Down();
	void Collide();
public:
	// Attack
	virtual void Attack();
	virtual void AttackEX();
};