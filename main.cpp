
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
//void test(Button<float> test){};

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
  
    Button<float> Button1(sf::Vector2f(20,20), 25,50, sf::Color::Red, sf::Color::Blue,5);
    
    Button<float> Button2(sf::Vector2f(20,20), 25,20, sf::Color::Cyan, sf::Color::Blue,5);
    
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
             Button1.update(event);
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Espace pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
           
        }
       
        // Clear screen
        window.clear();

        Button1.render(window);
        Button2.render(window);
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
