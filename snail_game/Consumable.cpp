#include "Consumable.h"

Consumable::Consumable(VisibleObject* p_body[])
{
	type = TEST;
	main_body = p_body[0];
	main_body = p_body[1];

	shuffleType();

	hitbox = main_body->sprite.getGlobalBounds();
}

void Consumable::render(sf::RenderWindow* p_window)
{
	main_body->render(p_window);
	hitbox = main_body->sprite.getGlobalBounds();
}

int Consumable::getType()
{
	return type;
}

void Consumable::respawn()
{

	position = sf::Vector2f(
	rand() % 600 + 0,
	rand() % 600 + 0
	);

	main_body->sprite.setPosition(position);
	


}

int Consumable::randomValue(int max, int min)
{
	float A = 0;
	float B = 0;
	float AB = 0;

	if (max == 0)
		max++;

	if (min == 0)
		min++;

	A = rand() % max + min;

	B = rand() % max + min;

	B = A - B;

	AB = (AB)+(A - B);

	return AB;

}

void Consumable::consume()
{
	respawn();
}

sf::FloatRect Consumable::getHitbox()
{
	return hitbox;
}

void Consumable::shuffleType()
{

}
