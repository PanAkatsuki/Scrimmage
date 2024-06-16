#include "Player.h"

// Constructor
Player::Player()
{
	current_animation = &animation_idel_left;

	timer_attack_cd.SetWaitTime(attack_cd);
	timer_attack_cd.SetOneShot(true);
	timer_attack_cd.SetCallback(
		[&]()
		{
			can_attack = true;
		}
	);

	timer_invulnerable.SetWaitTime(20);
	timer_invulnerable.SetOneShot(true);
	timer_invulnerable.SetCallback(
		[&]()
		{
			is_invulnerable = false;
		}
	);

	timer_invulnerable_blink.SetWaitTime(5);
	timer_invulnerable_blink.SetCallback(
		[&]()
		{
			is_showing_sketch_frame = !is_showing_sketch_frame;
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
				break;
			default:
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode)
			{
			case VK_LEFT: // '©'
				is_left_key_down = true;
				break;
			case VK_RIGHT: // '¨'
				is_right_key_down = true;
				break;
			case VK_UP: // 'ª'
				is_up_key_down = true;
				break;
			case VK_DOWN: // '«'
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
			case VK_LEFT: // '©'
				is_left_key_down = false;
				break;
			case VK_RIGHT: // '¨'
				is_right_key_down = false;
				break;
			case VK_UP: // 'ª'
				is_up_key_down = false;
				break;
			case VK_DOWN: // '«'
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
	// Gravity
	Gravity(delta);

	// MP
	if (mp > 100)
	{
		mp = 100;
	}

	// Move
	Run(delta);

	// Jump and down
	Jump();
	Down();

	// Collide
	Collide();

	// Update Animation
	current_animation->Update(delta);

	// Attack
	if(!can_attack)
	{
		timer_attack_cd.Update(delta);
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

void Player::Draw(Camera& camera)
{
	if (hp > 0 && is_invulnerable && is_showing_sketch_frame)
	{
		PutImageAlpha(camera, position.x, position.y, &img_sketch);
	}
	else
	{
		current_animation->Draw(camera, position.x, position.y);
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

void Player::SetVelocity(int x, int y)
{
	this->velocity.x = x;
	this->velocity.y = y;
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
			if (is_collide_x && is_collide_y)
			{
				if (position.y + size.y - velocity.y <= shape.y)
				{
					position.y = shape.y - size.y;
					velocity.y = 0;
					is_standing = true;
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
	}
	else
	{
		current_animation = is_facing_right ? &animation_idel_right : &animation_idel_left;
		velocity.x = 0;
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
	}
}

void Player::Down()
{
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