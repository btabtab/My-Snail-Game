#include "Leaf_Consumable.h"

Leaf::Leaf(VisibleObject p_body[])
{
	type = LEAF;

	main_body.loadImage("leaf.bmp");
	main_body.cleanup();
	main_body.applyImage();

	shuffleType();

}

void Leaf::render(sf::RenderWindow* p_window)
{
	main_body.render(p_window);
	
	hitbox = main_body.sprite.getGlobalBounds();
}

int Leaf::getType()
{
	return type;
}

void Leaf::respawn()
{

	position = sf::Vector2f(
		rand() % 600 + 0,
		rand() % 600 + 0
	);

	main_body.sprite.setPosition(position);

}

int Leaf::randomValue(int max, int min)
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

void Leaf::consume()
{
	shuffleType();

	respawn();
}

sf::FloatRect Leaf::getHitbox()
{
	return hitbox;
}

void Leaf::shuffleType()
{
	type == LEAF;
	return;
}
