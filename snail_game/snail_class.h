#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <string.h>

#include "Consumable.h"

#include "VisualObject_Struct.h"

#include "Consumable.h"



class Snail
{
public:

    Snail();

    void renderSnail(sf::RenderWindow* p_window);

    void think();

    void move();

    int randomValue(int max, int min);

    void grow();

    void calculateMood();

    void adjustMoodDisplay();

    void feed();

    void water();

    void polish();

    void changeDirection(sf::Vector2f target, sf::RenderWindow* p_window);

    void checkCollision(Consumable* p_consumable);

    void setPosition(sf::Vector2f n_position);

private:

    std::string name;

    VisibleObject main_body;

    sf::Clock internal_clock;

    sf::Clock time_since_food;
    sf::Clock time_since_water;
    sf::Clock time_since_polishing;


    bool is_hungry;
    bool is_thirsty;
    bool is_polishing;

    int age;

    sf::Clock time_since_swag_drop;
    int joy;

    sf::Clock time_since_last_move;
    sf::Vector2f position;
    sf::Vector2f direction;

    std::string mood;
    sf::Text mood_text;
    sf::Font mood_font;

    int food_until_grow;
    int water_until_grow;

    int food_eaten;
    sf::Text food_text;

    int water_drunk;
    sf::Text water_text;
};
