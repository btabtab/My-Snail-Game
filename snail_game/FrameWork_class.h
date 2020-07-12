#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "VisualObject_Struct.h"

#include "snail_class.h"

#include "Consumable.h"
#include "Water_Consumable.h"
#include "Leaf_Consumable.h"

class FrameWork
{
public:

    FrameWork(sf::RenderWindow* p_window);

    void mainLoop();

    void render(sf::RenderWindow* p_window);

    void gameTick();

    char handleInput();

    void updateMouse();

private:

    Snail main_snail;

    sf::RenderWindow* m_p_window;

    VisibleObject mouse_cursor;
    sf::Vector2f mouse_Pos;

    VisibleObject leaf_body_arr[2];
    VisibleObject water_body_arr[2];

    VisibleObject testBody;

    Consumable Test;

    Leaf leaf;
    Water water;

    int item_count;

    Leaf leaf_arr[10];
    Water water_arr[10];

    std::vector<Leaf*> leaf_vec;
    std::vector<Water*> water_vec;

    sf::Clock system_runtime;

    bool is_quick_cycle;
};