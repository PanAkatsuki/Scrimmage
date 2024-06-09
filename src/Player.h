#pragma once

#include <graphics.h>

#include "Vector2.h"
#include "Animation.h"
#include "Camera.h"

#include "Player_id.h"

class Player
{
public:
	Player()
	{
		current_animation = &animation_idel_left;
	}
	~Player() = default;
private:
	PlayerID id = PlayerID::P1;

	bool is_left_key_down = false;
	bool is_right_key_down = false;

	bool is_facing_right = true;

	Animation* current_animation = nullptr;
protected:
	Vector2 position;

	Animation animation_idel_left;
	Animation animation_idel_right;
	Animation animation_run_left;
	Animation animation_run_right;
public:
	virtual void Input(ExMessage& msg)
	{
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
	}
	virtual void Update(int delta)
	{
		int direction = is_right_key_down - is_left_key_down;

		if (direction != 0)
		{
			is_facing_right = (direction > 0);
			current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		}
		else
		{
			current_animation = is_facing_right ? &animation_idel_right : &animation_idel_left;
		}

		current_animation->Update(delta);
	}
	virtual void Draw(Camera& camera)
	{
		current_animation->Draw(camera, position.x, position.y);
	}
public:
	void SetID(PlayerID id);
	void SetPosition(int x, int y);
};