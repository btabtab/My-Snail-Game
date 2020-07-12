#include "FrameWork_class.h"

FrameWork::FrameWork(sf::RenderWindow* p_window)
{
	m_p_window = p_window;
	m_p_window->setFramerateLimit(60);

	mouse_cursor.loadImage("crosshair.bmp");
	mouse_cursor.cleanup();
	mouse_cursor.applyImage();

	mouse_cursor.sprite.setOrigin(
		mouse_cursor.image.getSize().x / 2,
		mouse_cursor.image.getSize().y / 2);

	p_window->setMouseCursorVisible(false);

	testBody.loadImage("test.bmp");
	testBody.cleanup();
	testBody.applyImage();

	leaf_body_arr[0].loadImage("leaf.bmp");
	leaf_body_arr[0].cleanup();
	leaf_body_arr[0].applyImage();

	leaf_body_arr[1].loadImage("leaf.bmp");
	leaf_body_arr[1].cleanup();
	leaf_body_arr[1].applyImage();


	water_body_arr[0].loadImage("water.bmp");
	water_body_arr[0].cleanup();
	water_body_arr[0].applyImage();

	water_body_arr[1].loadImage("water.bmp");
	water_body_arr[1].cleanup();
	water_body_arr[1].applyImage();

	//Test = Consumable(&testBody);
	//leaf = Leaf(&leafBody);
	//water = Water(&waterBody);

	//Test.respawn();
	//leaf.respawn();
	//water.respawn();


	system_runtime.restart();

	item_count = 9;

	//leaf_arr[0] = Leaf(leaf_body_arr);
	
	//water_arr[0] = Water(water_body_arr);

	for (int i = 0; i != item_count; i++)
	{

		leaf_vec.push_back(new Leaf(leaf_body_arr));
		water_vec.push_back(new Water(water_body_arr));

		srand(system_runtime.getElapsedTime().asMicroseconds() * item_count);
		leaf_vec.back()->respawn();
		//leaf_arr[0].respawn();

		srand(system_runtime.getElapsedTime().asMicroseconds() * item_count);
		water_vec.back()->respawn();
		//water_arr[0].respawn();

	}

	is_quick_cycle = false;

}

void FrameWork::mainLoop()
{
	srand(system_runtime.getElapsedTime().asMicroseconds());

	while(m_p_window->isOpen())
	{
		sf::Event event;
		while (m_p_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_p_window->close();
			}
		}

		gameTick();
		render(m_p_window);

		switch (is_quick_cycle)
		{
		case(true):
			is_quick_cycle = false;
			break;

		case(false):

			for (int i = 0; i != leaf_vec.size(); i++)
			{
				main_snail.checkCollision(leaf_vec.at(i));
				main_snail.checkCollision(water_vec.at(i));
			}
			is_quick_cycle = true;
			break;
		}



		//main_snail.checkCollision(&leaf_arr[0]);

		//main_snail.checkCollision(&water_arr[0]);

		//main_snail.checkCollision(&Test);
		//main_snail.checkCollision(&leaf);
		//main_snail.checkCollision(&water);
	}

}

void FrameWork::render(sf::RenderWindow* p_window)
{
	p_window->clear();
	
	main_snail.renderSnail(p_window);

	for (int i = 0; i != leaf_vec.size(); i++)
	{
		leaf_vec.at(i)->render(p_window);
		water_vec.at(i)->render(p_window);
	}

	mouse_cursor.render(p_window);

	//leaf_arr[0].render(p_window);
	//water_arr[0].render(p_window);

	p_window->display();

	//Test.render(p_window);
	//leaf.render(p_window);
	//water.render(p_window);
}

void FrameWork::gameTick()
{

	main_snail.think();

	//if (handleInput() == 'R')
	//{
	//	main_snail.feed();
	//}
	//
	//if (handleInput() == 'T')
	//{
	//	main_snail.water();
	//}
	//
	//if (handleInput() == 'Y')
	//{
	//	leaf_vec.push_back(new Leaf(leaf_body_arr));
	//	water_vec.push_back(new Water(water_body_arr));
	//}

	updateMouse();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		main_snail.changeDirection(sf::Vector2f(sf::Mouse::getPosition(*m_p_window)), m_p_window);
		//std::cout << "changed direction";
		//std::cout << std::endl;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		main_snail.setPosition(sf::Vector2f(300.f, 300.f));
	}


}

char FrameWork::handleInput()
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		return 'R';
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		return 'T';
	}

}

void FrameWork::updateMouse()
{

	mouse_Pos = sf::Vector2f(sf::Mouse::getPosition(*m_p_window));

	mouse_cursor.sprite.setPosition(mouse_Pos);

}
