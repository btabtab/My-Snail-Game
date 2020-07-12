#include <vector>

#include <SFML/Graphics.hpp>

#include "snail_class.h"
#include "FrameWork_class.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(600.f, 600.f), "My snail game");

    FrameWork framework(&window);

    framework.mainLoop();

}