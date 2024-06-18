#pragma once

#include <graphics.h>

#include "Animation.h"
#include "Particle.h"
#include "Camera.h"
#include "Platform.h"
#include "Bullet.h"

#include "Player_id.h"
#include "Character.h"

#include "SketchImage.h"

extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern Atlas atlas_run_effect;
extern Atlas atlas_jump_effect;
extern Atlas atlas_land_effect;

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

	// Jump effect
	Vector2 position_jump_effect;
	const int jump_effect_interval = 2;
	bool is_jump_effect_visible = false;

	// Land effect
	Vector2 position_land_effect;
	const int land_effect_interval = 4;
	bool is_land_effect_visible = false;

	// Attack
	bool can_attack = true;
	int attack_cd = 30;
	Timer timer_attack_cd;

	// Attack ex
	bool is_attack_ex = false;
	bool is_mp_not_enough = false;
	const int text_mp_not_enough_duration = 30;
	Timer timer_is_mp_not_enough;

	// Invulnerbale
	IMAGE img_sketch;
	bool is_invulnerable = false;
	const int invulnerable_duration = 10;
	Timer timer_invulnerable;
	bool is_showing_sketch_frame = false;
	const int blink_duration = 2;
	Timer timer_invulnerable_blink;

	// Animation
	Animation* current_animation = nullptr;

	// Particle
	std::vector<Particle> particle_list;
	Timer timer_run_effect_generation;
	const int run_effect_genneration_cd = 10;
	const int run_effect_genneration_lifespan = 3;
	Timer timer_die_effect_generation;
	const int die_effect_genneration_cd = 10;
	const int die_effect_genneration_lifespan = 2;
protected:
	// Gravity
	int gravity = 1;

	// Speed
	int run_speed = 5;
	int jump_speed = -20;

	// hp mp
	int hp = 100;
	int mp = 0;

	// ID Character
	PlayerID id = PlayerID::P1;
	Character character = Character::NONE;

	// Size
	Vector2 size = { 0, 0 };

	// Position
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

	// Jump animation
	Animation animation_jump_effect;
	Animation animation_land_effect;
	
public:
	// Default
	virtual void Input(ExMessage& msg);
	virtual void Update(int& delta);
	virtual void Draw(Camera& camera);
public:
	// Set
	void SetID(PlayerID id);
	void SetCharacter(Character chara);
	void SetSize(int x, int y);
	void SetPosition(int x, int y);
	void SetVelocity(int x, int y);
	void SetHP(int val);
	void SetMP(int val);

	// Get
	PlayerID GetId() const;
	Character GetCharacter() const;
	Vector2 GetSize() const;
	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
	int GetHP() const;
	int GetMP() const;
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

	// Invulnerable
	void MakeInvulnerable();
};