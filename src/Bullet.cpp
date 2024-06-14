#include "Bullet.h"

// Set
void Bullet::SetSize(Vector2& vec)
{
	size = vec;
}

void Bullet::SetPosition(Vector2& vec)
{
	position.x = vec.x;
	position.y = vec.y;
}

void Bullet::SetVelocity(Vector2& vec)
{
	velocity = vec;
}

void Bullet::SetDamage(int val)
{
	damage = val;
}

void Bullet::SetValid(bool flag)
{
	valid = flag;
}

void Bullet::SetCanRemove(bool flag)
{
	can_remove = flag;
}

void Bullet::SetTargetID(PlayerID id)
{
	target_id = id;
}

void Bullet::SetCallback(std::function<void()> callback)
{
	this->callback = callback;
}

// Get
Vector2 Bullet::GetSize() const
{
	return size;
}

Vector2 Bullet::GetPosition() const
{
	return position;
}

Vector2 Bullet::GetVelocity() const
{
	return velocity;
}

int Bullet::GetDamage() const
{
	return damage;
}

bool Bullet::GetValid() const
{
	return valid;
}

bool Bullet::GetCanRemove() const
{
	return can_remove;
}

PlayerID Bullet::GetTargetID() const
{
	return target_id;
}

// Default
void Bullet::Update(int& delta)
{

}

void Bullet::Draw(Camera& camera) const
{

}

// Check
bool Bullet::CheckBulletExceedsScreen()
{
	return (position.x + size.x <= 0
		|| position.x >= getwidth()
		|| position.y + size.y <= 0
		|| position.y >= getheight());
}

// Collide
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