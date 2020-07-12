#pragma once

#include <SFML/Graphics.hpp>

#include "VisualObject_Struct.h"

enum types
{
	TEST,
	LEAF,
	WATER,
	CACTUS,
	PUDDLE
};

class Consumable
{
public:

	Consumable() {}

	Consumable(VisibleObject* p_body[]);

	virtual void render(sf::RenderWindow* p_window);
	
	virtual int getType();
	
	virtual void respawn();
	
	virtual int randomValue(int max, int min);
	
	virtual void consume();
	
	virtual sf::FloatRect getHitbox();

	virtual void shuffleType();

private:

	int type;

	VisibleObject* main_body;

	sf::Vector2f position;

	sf::FloatRect hitbox;
};