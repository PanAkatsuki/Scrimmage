#include "Player.h"

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
void Player::Update(int delta)
{
	run(delta);
	jump(delta);
	Gravity(delta);

	current_animation->Update(delta);
}
void Player::Draw(Camera& camera)
{
	current_animation->Draw(camera, position.x, position.y);

	if (is_debug)
	{
		setlinecolor(RGB(255, 0, 0));
		DebugLine(camera, position.x, position.y, position.x + size.x, position.y);
		DebugLine(camera, position.x + size.x, position.y, position.x + size.x, position.y + size.y);
		DebugLine(camera, position.x, position.y + size.y, position.x + size.x, position.y + size.y);
		DebugLine(camera, position.x, position.y, position.x, position.y + size.y);
	}
	if (is_debug)
	{
		settextcolor(RGB(255, 0, 0));
		if(is_standing)
		{
			outtextxy(position.x, position.y - 20, _T("is_standing = true"));
		}
		else if (!is_standing)
		{
			outtextxy(position.x, position.y - 20, _T("is_standing = false"));
		}
	}
}
// Set
void Player::SetID(PlayerID id)
{
	this->id = id;
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
void Player::run(int delta)
{
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
void Player::jump(int delta)
{
	if(is_standing && is_up_key_down)
	{
		velocity.y += jump_speed;
		is_standing = false;
	}
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
					is_double_jump = false;
					break;
				}
			}
		}
	}
}