#include "Peashooter.h"

void Peashooter::Update(int delta)
{
	Player::Update(delta);

	std::cout << "Peashooter is updating" << std::endl;
}