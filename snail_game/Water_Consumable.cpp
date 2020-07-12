#include "Water_Consumable.h"

Water::Water(VisibleObject p_body[])
{
	type = WATER;

	main_body.loadImage("water.bmp");
	main_body.cleanup();
	main_body.applyImage();

	shuffleType();

}

void Water::render(sf::RenderWindow* p_window)
{
	main_body.render(p_window);

	hitbox = main_body.sprite.getGlobalBounds();
}

int Water::getType()
{
	return type;
}

void Water::respawn()
{

	position = sf::Vector2f(
		rand() % 600 + 0,
		rand() % 600 + 0
	);

	main_body.sprite.setPosition(position);

}

int Water::randomValue(int max, int min)
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

void Water::consume()
{
	respawn();
}

sf::FloatRect Water::getHitbox()
{
	return hitbox;
}

void Water::shuffleType()
{

}
