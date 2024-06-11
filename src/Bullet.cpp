#include "Bullet.h"

void Bullet::SetSize(Vector2& vec)
{
	size = vec;
}
Vector2 Bullet::GetSize() const
{
	return size;
}
void Bullet::SetPosition(Vector2& vec)
{
	position.x = vec.x;
	position.y = vec.y;
}
Vector2 Bullet::GetPosition() const
{
	return position;
}
void Bullet::SetVelocity(Vector2& vec)
{
	velocity = vec;
}
Vector2 Bullet::GetVelocity() const
{
	return velocity;
}
void Bullet::SetDamage(int val)
{
	damage = val;
}
int Bullet::GetDamage() const
{
	return damage;
}
void Bullet::SetValid(bool flag)
{
	valid = flag;
}
bool Bullet::GetValid() const
{
	return valid;
}
void Bullet::SetCanRemove(bool flag)
{
	can_remove = flag;
}
bool Bullet::GetCanRemove() const
{
	return can_remove;
}
void Bullet::SetTargetID(PlayerID id)
{
	target_id = id;
}
PlayerID Bullet::GetTargetID() const
{
	return target_id;
}
void Bullet::SetCallback(std::function<void()> callback)
{
	this->callback = callback;
}

void Bullet::Update(int delta)
{

}
void Bullet::Draw(Camera& camera)
{

}

bool Bullet::CheckBulletExceedsScreen()
{
	return (position.x + size.x <= 0
		|| position.x >= getwidth()
		|| position.y + size.y <= 0
		|| position.y >= getheight());
}

void Bullet::Collide() const
{
	if (callback)
	{
		callback();
	}
}
bool Bullet::CheckCollision(Vector2& position, Vector2& size) const
{
	return (this->position.x + this->size.x / 2 >= position.x
		&& this->position.x + this->size.x / 2 <= position.x + size.x
		&& this->position.y + this->size.y / 2 >= position.y
		&& this->position.y + this->size.y / 2 <= position.y + size.y);
}