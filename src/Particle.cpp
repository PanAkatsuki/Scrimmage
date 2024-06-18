#include "Particle.h"

// Default
void Particle::Update(int& delta)
{
	timer += delta;
	if (timer >= lifespan)
	{
		timer = 0;
		idx_frame++;
		if (idx_frame >= atlas->GetSize())
		{
			idx_frame = atlas->GetSize() - 1;
			valid = false;
		}
	}
}

void Particle::Draw(Camera& camera)
{
	PutImageAlpha(camera, position.x, position.y, atlas->GetImage(idx_frame));
}

// Set
void Particle::SetAtlas(Atlas* atlas)
{
	this->atlas = atlas;
}

void Particle::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Particle::SetLifespan(int val)
{
	lifespan = val;
}

// Check
bool Particle::CheckValid()
{
	return valid;
}
