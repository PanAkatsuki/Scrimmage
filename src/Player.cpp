#include "Player.h"

// Constructor
Player::Player()
{
	// Animaiton
	current_animation = &animation_idel_left;

	// Jump animation
	animation_jump_effect.SetAtlas(&atlas_jump_effect);
	animation_jump_effect.SetInterval(jump_effect_interval);
	animation_jump_effect.SetLoop(false);
	animation_jump_effect.SetCallBack(
		[&]()
		{
			is_jump_effect_visible = false;
		}
	);
	
	// Land animation
	animation_land_effect.SetAtlas(&atlas_land_effect);
	animation_land_effect.SetInterval(land_effect_interval);
	animation_land_effect.SetLoop(false);
	animation_land_effect.SetCallBack(
		[&]()
		{
			is_land_effect_visible = false;
		}
	);

	// Attack cd
	timer_attack_cd.SetWaitTime(attack_cd);
	timer_attack_cd.SetOneShot(true);
	timer_attack_cd.SetCallback(
		[&]()
		{
			can_attack = true;
		}
	);

	// Text mp is not enough
	timer_is_mp_not_enough.SetWaitTime(text_mp_not_enough_duration);
	timer_is_mp_not_enough.SetOneShot(true);
	timer_is_mp_not_enough.SetCallback(
		[&]()
		{
			is_mp_not_enough = false;
		}
	);

	// Invulnerable
	timer_invulnerable.SetWaitTime(invulnerable_duration);
	timer_invulnerable.SetOneShot(true);
	timer_invulnerable.SetCallback(
		[&]()
		{
			is_invulnerable = false;
		}
	);

	timer_invulnerable_blink.SetWaitTime(blink_duration);
	timer_invulnerable_blink.SetCallback(
		[&]()
		{
			is_showing_sketch_frame = !is_showing_sketch_frame;
		}
	);

	// Run effect
	timer_run_effect_generation.SetWaitTime(run_effect_genneration_cd);
	timer_run_effect_generation.SetCallback(
		[&]()
		{
			// Set atlas
			Particle particle;
			particle.SetAtlas(&atlas_run_effect);

			// Set position
			Vector2 particle_position;
			IMAGE* frame = atlas_run_effect.GetImage(0);
			particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
			particle_position.y = position.y + size.y - frame->getheight();
			particle.SetPosition(particle_position.x, particle_position.y);

			// Set lifespan
			particle.SetLifespan(run_effect_genneration_lifespan);

			// Emplace back
			particle_list.emplace_back(particle);
		}
	);

	// Die effect
	timer_die_effect_generation.SetWaitTime(die_effect_genneration_cd);
	timer_die_effect_generation.SetCallback(
		[&]()
		{
			// Set atlas
			Particle particle;
			particle.SetAtlas(&atlas_run_effect);

			// Set position
			Vector2 particle_position;
			IMAGE* frame = atlas_run_effect.GetImage(0);
			particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
			particle_position.y = position.y + size.y - frame->getheight();
			particle.SetPosition(particle_position.x, particle_position.y);

			// Set lifespan
			particle.SetLifespan(die_effect_genneration_lifespan);

			// Emplace back
			particle_list.emplace_back(particle);
		}
	);

	// Cursor
	timer_cursor_visible.SetWaitTime(180);
	timer_cursor_visible.SetOneShot(true);
	timer_cursor_visible.SetCallback(
		[&]()
		{
			is_cursor_visible = false;
		}
	);
}

// Default
void Player::Input(ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (id)
		{
		case PlayerID::P1:
			switch (msg.vkcode)
			{
			case 0x41: // 'A'
				is_left_key_down = true;
				break;
			case 0x44: // 'D'
				is_right_key_down = true;
				break;
			case 0x57: // 'W'
				is_up_key_down = true;
				break;
			case 0x53: // 'S'
				is_down_key_down = true;
				break;	
			case 0x46: // 'F'
				if (can_attack)
				{
					Attack();
					can_attack = false;
					timer_attack_cd.Restart();
				}
				break;
			case 0x47: // 'G'
				if (mp >= 100)
				{
					AttackEX();
					mp = 0;
				}
				else
				{
					is_mp_not_enough = true;
					timer_is_mp_not_enough.Restart();
				}
				break;
			default:
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode)
			{
			case VK_LEFT: // 'Å©'
				is_left_key_down = true;
				break;
			case VK_RIGHT: // 'Å®'
				is_right_key_down = true;
				break;
			case VK_UP: // 'Å™'
				is_up_key_down = true;
				break;
			case VK_DOWN: // 'Å´'
				is_down_key_down = true;
				break;
			case VK_OEM_PERIOD: // '.'
				if (can_attack)
				{
					Attack();
					can_attack = false;
					timer_attack_cd.Restart();
				}
				break;
			case VK_OEM_2: // '/'
				if (mp >= 100)
				{
					AttackEX();
					mp = 0;
				}
				else
				{
					is_mp_not_enough = true;
					timer_is_mp_not_enough.Restart();
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (id)
		{
		case PlayerID::P1:
			switch (msg.vkcode)
			{
			case 0x41: // 'A'
				is_left_key_down = false;
				break;
			case 0x44: // 'D'
				is_right_key_down = false;
				break;
			case 0x57: // 'W'
				is_up_key_down = false;
				break;
			case 0x53: // 'S'
				is_down_key_down = false;
				break;
			default:
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode)
			{
			case VK_LEFT: // 'Å©'
				is_left_key_down = false;
				break;
			case VK_RIGHT: // 'Å®'
				is_right_key_down = false;
				break;
			case VK_UP: // 'Å™'
				is_up_key_down = false;
				break;
			case VK_DOWN: // 'Å´'
				is_down_key_down = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Player::Update(int& delta)
{
	if (!is_dead)
	{
		// Gravity
		Gravity(delta);

		// HP
		if (hp < 0)
		{
			hp = 0;
			is_dead = true;
		}

		// Check out of stage
		if (position.x + size.x <= 0 || position.x >= getwidth() || position.y + size.y <= 0 || position.y >= getheight())
		{
			hp = 0;
			is_dead = true;
		}

		// MP
		if (mp > 100)
		{
			mp = 100;
		}

		// Move
		Run(delta);

		// Jump
		Jump();

		// Down
		Down();

		// Collide
		Collide();

		// Attack
		if (!can_attack)
		{
			timer_attack_cd.Update(delta);
		}

		// Attack EX
		if (is_mp_not_enough)
		{
			timer_is_mp_not_enough.Update(delta);
		}

		// Invulnerable
		if (is_invulnerable)
		{
			timer_invulnerable.Update(delta);
			timer_invulnerable_blink.Update(delta);
		}

		if (is_showing_sketch_frame)
		{
			SketchImage(current_animation->GetFrame(), &img_sketch);
		}
	}
	else if (is_dead)
	{
		position.x += velocity.x;
		is_standing = false;
		velocity.y += gravity * delta;
		position.y += velocity.y;
	}

	// Update animation
	current_animation->Update(delta);

	// Update jump animation
	if (is_jump_effect_visible)
	{
		animation_jump_effect.Update(delta);
	}
	
	// Update land animation
	if (is_land_effect_visible)
	{
		animation_land_effect.Update(delta);
	}

	// Update run particle
	timer_run_effect_generation.Update(delta);

	// Update die particle
	if (is_dead)
	{
		timer_die_effect_generation.Update(delta);
	}

	// Update all particle
	for (Particle& particle : particle_list)
	{
		particle.Update(delta);
	}

	// Delete invalid run particle
	particle_list.erase(std::remove_if(
		particle_list.begin(), particle_list.end(),
		[](Particle particle)
		{
			bool deletable = !particle.CheckValid();
			if (deletable)
			{
				return deletable;
			}
			return false;
		}),
		particle_list.end());

	// Update cursor
	if (is_cursor_visible)
	{
		timer_cursor_visible.Update(delta);
	}
}

void Player::Draw(Camera& camera)
{
	// Draw particle
	for (Particle& particle : particle_list)
	{
		particle.Draw(camera);
	}

	// Draw jump effect
	if (is_jump_effect_visible)
	{
		animation_jump_effect.Draw(camera, position_jump_effect.x, position_jump_effect.y);
	}

	// Draw land effect
	if (is_land_effect_visible)
	{
		animation_land_effect.Draw(camera, position_land_effect.x, position_land_effect.y);
	}

	// Draw player id
	switch (is_cursor_visible)
	{
	case true:
		switch (id)
		{
		case PlayerID::P1:
			PutImageAlpha(camera, position.x + (size.x - img_1p_cursor.getwidth()) / 2, position.y - img_1p_cursor.getheight(), &img_1p_cursor);
			break;
		case PlayerID::P2:
			PutImageAlpha(camera, position.x + (size.x - img_2p_cursor.getwidth()) / 2, position.y - img_2p_cursor.getheight(), &img_2p_cursor);
			break;
		}
		break;
	case false:
		switch (id)
		{
		case PlayerID::P1:
			settextcolor(RGB(255, 255, 0));
			outtextxy(position.x + size.x / 3, position.y - 20, _T("1P"));
			break;
		case PlayerID::P2:
			settextcolor(RGB(255, 0, 0));
			outtextxy(position.x + size.x / 3, position.y - 20, _T("2P"));
			break;
		}
		break;
	}

	// Draw character
	if (hp > 0 && is_invulnerable && is_showing_sketch_frame)
	{
		PutImageAlpha(camera, position.x, position.y, &img_sketch);
	}
	else
	{
		current_animation->Draw(camera, position.x, position.y);
	}

	if (is_mp_not_enough)
	{
		settextcolor(RGB(255, 255, 255));
		outtextxy(position.x + 20, position.y - 20, _T("mp"));
	}

	if (is_debug)
	{
		setlinecolor(RGB(0, 255, 0));
		DebugLine(camera, position.x, position.y, position.x + size.x, position.y);
		DebugLine(camera, position.x + size.x, position.y, position.x + size.x, position.y + size.y);
		DebugLine(camera, position.x, position.y + size.y, position.x + size.x, position.y + size.y);
		DebugLine(camera, position.x, position.y, position.x, position.y + size.y);

		settextcolor(RGB(255, 255, 255));
		switch (can_attack)
		{
		case true:
			outtextxy(position.x, position.y - 70, _T("can_attack = true"));
			break;
		case false:
			outtextxy(position.x, position.y - 70, _T("can_attack = false"));
			break;
		}
		switch (is_standing)
		{
		case true:
			outtextxy(position.x, position.y - 50, _T("is_standing = true"));
			break;
		case false:
			outtextxy(position.x, position.y - 50, _T("is_standing = false"));
			break;
		}
		switch (can_jump)
		{
		case true:
			outtextxy(position.x, position.y - 30, _T("can_jump = true"));
			break;
		case false:
			outtextxy(position.x, position.y - 30, _T("can_jump = false"));
			break;
		}
	}
}

// Set
void Player::SetID(PlayerID id)
{
	this->id = id;
}

void Player::SetCharacter(Character chara)
{
	character = chara;
}

void Player::SetSize(int x, int y)
{
	this->size.x = x;
	this->size.y = y;
}

void Player::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void Player::SetFacingRight(bool is_facing_right)
{
	this->is_facing_right = is_facing_right;
}

void Player::SetVelocity(int x, int y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

void Player::SetHP(int val)
{
	hp = val;
}

void Player::SetMP(int val)
{
	mp = val;
}

// Get
PlayerID Player::GetId() const
{
	return this->id;
}

Character Player::GetCharacter() const
{
	return character;
}

Vector2 Player::GetSize() const
{
	return this->size;
}

Vector2 Player::GetPosition() const
{
	return this->position;
}

bool Player::GetFacingRight() const
{
	return is_facing_right;
}

Vector2 Player::GetVelocity() const
{
	return this->velocity;
}

int Player::GetHP() const
{
	return hp;
}

int Player::GetMP() const
{
	return mp;
}


void Player::Gravity(int delta)
{
	bool last_is_standing = is_standing;
	is_standing = false;
	velocity.y += gravity * delta;
	position.y += velocity.y;

	if (velocity.y > 0)
	{
		for (const Platform& platform : platform_list)
		{
			const Platform::CollisionShape& shape = platform.shape;

			bool is_collide_x = (max(position.x + size.x, shape.right) - min(position.x, shape.left) <=
				shape.right - shape.left + size.x);
			bool is_collide_y = (position.y <= shape.y && position.y + size.y >= shape.y);

			// Land on platform
			if (is_collide_x && is_collide_y)
			{
				if (position.y + size.y - velocity.y <= shape.y)
				{
					position.y = shape.y - size.y;
					velocity.y = 0;
					is_standing = true;

					// Land effect
					if (!last_is_standing)
					{
						// Set land effect visible
						is_land_effect_visible = true;

						// Set land effect position
						position_land_effect.x = position.x + (size.x - animation_land_effect.GetFrame()->getwidth()) / 2;
						position_land_effect.y = position.y + size.y - animation_land_effect.GetFrame()->getheight();

						// Reset land animation
						animation_land_effect.Reset();

					}
					
					break;
				}
			}
		}
	}
}

void Player::Run(int delta)
{
	if (is_attack_ex)
	{
		return;
	}

	int direction = is_right_key_down - is_left_key_down;

	if (direction != 0)
	{
		is_facing_right = (direction > 0);
		current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		velocity.x = direction * run_speed * delta;
		//timer_run_effect_generation.SetPause(false);
		timer_run_effect_generation.SetPause(true);
	}
	else
	{
		current_animation = is_facing_right ? &animation_idel_right : &animation_idel_left;
		velocity.x = 0;
		timer_run_effect_generation.SetPause(true);
	}

	position.x += velocity.x;
}

void Player::Jump()
{
	if (is_attack_ex)
	{
		return;
	}

	if (is_up_key_down && is_standing && can_jump)
	{
		velocity.y += jump_speed;

		// Set jump effect
		// Set jump effect visible
		is_jump_effect_visible = true;

		// Set jump effect position
		position_jump_effect.x = position.x + (size.x - animation_jump_effect.GetFrame()->getwidth()) / 2;
		position_jump_effect.y = position.y + size.y - animation_jump_effect.GetFrame()->getheight();

		// Reset jump animation
		animation_jump_effect.Reset();
	}
}

void Player::Down()
{
	if (!is_down_key_down)
	{
		return;
	}

	if (is_attack_ex)
	{
		return;
	}

	for(size_t i = 1; i < platform_list.size(); i++)
	{
		if (is_down_key_down && is_standing && position.y + size.y == platform_list[i].shape.y)
		{
			position.y += gravity;
		}
	}
}

void Player::Collide()
{
	if (is_invulnerable)
	{
		return;
	}

	for (Bullet* bullet : bullet_list)
	{
		if(!bullet->GetValid() || bullet->GetTargetID() != id)
		{
			continue;
		}

		if (bullet->CheckCollision(position, size))
		{
			MakeInvulnerable();
			bullet->Collide();
			bullet->SetValid(false);
			hp -= bullet->GetDamage();

			// Die
			last_hurt_direction.x = bullet->GetPosition().x - position.x;
			last_hurt_direction.y = bullet->GetPosition().y - position.y;
			if (hp <= 0)
			{
				// Die animation
				last_hurt_direction.x > 0 ? velocity.x += -10 : velocity.x += 10;
				velocity.y -= 25;

				// Die bool
				is_dead = true;

				// Die particle
				timer_die_effect_generation.Restart();
			}
		}
	}
}

// Attack
void Player::Attack()
{

}

void Player::AttackEX()
{

}

// Invulnerable
void Player::MakeInvulnerable()
{
	is_invulnerable = true;
	timer_invulnerable.Restart();
}