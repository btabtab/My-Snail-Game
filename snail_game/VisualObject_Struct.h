#pragma once

#include <SFML/Graphics.hpp>

struct VisibleObject
{
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;

    sf::Shader shader;

    void cleanup()
    {
        for (int X = 0; X != image.getSize().x; X++)
        {
            for (int Y = 0; Y != image.getSize().y; Y++)
            {
                if (image.getPixel(X, Y) == sf::Color::Black)
                {
                    image.setPixel(X, Y, sf::Color::Transparent);
                }
            }
        }
    }

    void applyImage()
    {
        texture.loadFromImage(image);
        sprite.setTexture(texture);

        sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);

    }

    void loadImage(std::string image_name)
    {
        image.loadFromFile(image_name);
    }

    void render(sf::RenderWindow* p_window)
    {
        //std::cout << "rendered";
        //std::cout << std::endl;

        p_window->draw(sprite);
    }

    int randomValue(int max, int min)
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


    void giveImagePattern(int seed)
    {
        srand(seed);

        int rndm_col[3];
        int base_col[3] = 
        {
            127,
            127,
            127
        };

        rndm_col[0] = rand() % 255 + 0;
        rndm_col[1] = rand() % 255 + 0;
        rndm_col[2] = rand() % 255 + 0;

        //rndm_R /= 1000;
        //rndm_G /= 1000;
        //rndm_B /= 1000;
        //sf::Color base_colour = sf::Color(rndm_R, rndm_G, rndm_B);

        //std::cout << "R : " << rndm_col[0] << " ";
        //std::cout << "G : " << rndm_col[1] << " ";
        //std::cout << "B : " << rndm_col[2] << " ";
        //std::cout << std::endl;
        
        //sf::Color base_colour = sf::Color(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0);

        for (int x = 0; x != image.getSize().x; x++)
        {

            for (int y = 0; y != image.getSize().y; y++)
            {
                if (image.getPixel(x, y) == sf::Color(210.f, 210.f, 210.f))
                {

                    rndm_col[0] = rand() % (int)base_col[0] * 1.2 + (int)base_col[0] * 0.8;
                    rndm_col[1] = rand() % (int)base_col[1] * 1.2 + (int)base_col[1] * 0.8;
                    rndm_col[2] = rand() % (int)base_col[2] * 1.2 + (int)base_col[2] * 0.8;

                    image.setPixel(x, y, sf::Color(rndm_col[0], rndm_col[1], rndm_col[2]));

                    //std::cout << "R : " << rndm_col[0] << " ";
                    //std::cout << "G : " << rndm_col[1] << " ";
                    //std::cout << "B : " << rndm_col[2] << " ";
                    //std::cout << std::endl;

                }
                
            }
        }

    }

};