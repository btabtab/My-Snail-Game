#include "snail_class.h"

Snail::Snail()
{

	main_body.image.loadFromFile("body_image.bmp");
	main_body.giveImagePattern(12139);
	main_body.cleanup();
	main_body.applyImage();

	internal_clock.restart();
	time_since_food.restart();
	time_since_water.restart();
	time_since_polishing.restart();
	time_since_swag_drop.restart();
	time_since_last_move.restart();

	mood_font.loadFromFile("Qiko.ttf");
	mood_text.setFont(mood_font);

	age = 1;

	position = sf::Vector2f(300.f, 300.f);

	main_body.sprite.setScale(sf::Vector2f(0.25f, 0.25f));

	mood_text.scale(0.5f, 0.5f);

	joy = 50;

	food_until_grow = 2;
	water_until_grow = 2;

	food_eaten = 0;
	water_drunk = 0;

	water_text.setFont(mood_font);
	food_text.setFont(mood_font);

	water_text.setPosition(10.f, 10.f);
	food_text.setPosition(10.f, 30.f);

	main_body.sprite.setPosition(position);
}

void Snail::renderSnail(sf::RenderWindow* p_window)
{

	p_window->draw(main_body.sprite);
	p_window->draw(mood_text);

	p_window->draw(water_text);
	p_window->draw(food_text);

}

void Snail::think()
{

	food_text.setString("food eaten: " + std::to_string(food_eaten) + " / " + std::to_string(food_until_grow));
	water_text.setString("water drunk: " + std::to_string(water_drunk) + " / " + std::to_string(water_until_grow));

	if (water_drunk >= water_until_grow
		&&
		food_eaten >= food_until_grow)
	{
		grow();
	}	

	adjustMoodDisplay();

	if (time_since_last_move.getElapsedTime().asSeconds() > ((4.5 / (age / 0.75)) - (joy / 100)))
	{
		move();

		main_body.sprite.setPosition(position);
		
		time_since_last_move.restart();
	}	

	if (time_since_food.getElapsedTime().asSeconds() > (10 * age) + joy)
	{
		is_hungry = true;
		//std::cout << "snail is hungry";
		//std::cout << std::endl;

		joy -= 1;

		time_since_food.restart();

	}

	if (time_since_water.getElapsedTime().asSeconds() > (5 * age) + joy / 2)
	{
		joy -= 1;

		is_thirsty = true;
		//std::cout << "snail is thirsty";
		//std::cout << std::endl;

		time_since_water.restart();

	}

	if (is_hungry
		&& 
		is_thirsty
		&& 
		time_since_swag_drop.getElapsedTime().asSeconds() > 5)
	{
		joy -= 10;
		adjustMoodDisplay();

		//std::cout << "joy = " << joy;
		//std::cout << std::endl;

		time_since_swag_drop.restart();
	}

	if (joy >= 100)
	{
		joy = 100;
	}
	if (0 >= joy)
	{
		joy = 0;
	}

}

void Snail::move()
{
	//randomValue(3, 1);
	//randomValue(3, 1);
	position.x += direction.x;
	position.y += direction.y;
}

int Snail::randomValue(int max, int min)
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

void Snail::grow()
{

	age++;

	float very_small_number = 0.01;
	main_body.sprite.setScale(0.25 + (age * 0.01), 0.25 + (age * 0.01));
		
	joy = 50;
	
	//std::cout << name << " has grown";
	//std::cout << std::endl;
	

	switch (food_until_grow)
	{
	default:
		food_until_grow *= 1.3;
		break;

	case(2):
		food_until_grow = 3;
		break;

	case(3):
		food_until_grow = 5;
		break;
	}

	switch (water_until_grow)
	{
	default:
		water_until_grow *= 1.3;
		break;

	case(2):
		water_until_grow = 3;
		break;

	case(3):
		water_until_grow = 5;
		break;
	}

	food_eaten = 0;
	water_drunk = 0;

}

void Snail::calculateMood()
{

	if (100 >= joy
		&& joy <= 90)
	{
		mood = "(OuO )";
	}

	if (89 >= joy
		&& joy <= 75)
	{
		mood = ".~(-o-)~`";
	}

	if (74 >= joy
		&& joy <= 50)
	{
		mood = "( @V@)/";
	}

	if (49 >= joy
		&& joy <= 25)
	{
		mood = "/( >w<)/";
	}

	if (24 >= joy
		&& joy <= 0)
	{
		mood = "( TnT)";
	}
	

}

void Snail::adjustMoodDisplay()
{

	calculateMood();

	mood_text.setString(mood);
	mood_text.setPosition(position + sf::Vector2f(-10, 10));

}

void Snail::feed()
{
	if (time_since_food.getElapsedTime().asSeconds() > 0.5)
	{
		food_eaten++;
		time_since_food.restart();

		joy += 5;

	}
}

void Snail::water()
{
	if (time_since_water.getElapsedTime().asSeconds() > 0.5)
	{
		water_drunk++;
		time_since_water.restart();

		joy += 5;

	}

}

void Snail::changeDirection(sf::Vector2f target, sf::RenderWindow* p_window)
{
	//direction.x = 0;
	//direction.y = 0;
	//sf::Vector2f(m_p_window->getSize().x, m_p_window->getSize().x

	target.x -= p_window->getSize().x / 2;
	target.y -= p_window->getSize().y / 2;

	direction.x = target.x / 100;
	direction.y = target.y / 100;

	//std::cout << "X: " << direction.x;
	//std::cout << "Y: " << direction.y << std::endl;
}

void Snail::checkCollision(Consumable* p_consumable)
{
	if (p_consumable->getHitbox().intersects(main_body.sprite.getGlobalBounds()))
	{
		int type = p_consumable->getType();

		switch (type)
		{
		default:
			return;
			break;

		case(TEST):
			p_consumable->consume();
			return;

			break;

		case(LEAF):
			feed();
			p_consumable->consume();
			return;

			break;

		case(WATER):
			water();
			p_consumable->consume();
			return;
			break;
		}
	}
}

void Snail::setPosition(sf::Vector2f n_position)
{

	position = n_position;

}
