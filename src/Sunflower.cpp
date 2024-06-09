#include "Sunflower.h"

void Sunflower::Update(int delta)
{
	Player::Update(delta);

	std::cout << "Sunflower is updating" << std::endl;
}