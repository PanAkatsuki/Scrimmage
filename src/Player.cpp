#include "Player.h"

void Player::SetID(PlayerID id)
{
	this->id = id;
}
void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}