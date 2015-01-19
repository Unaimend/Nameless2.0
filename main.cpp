
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"


int main(int, char const**)
{
    // Create the main window
    int xauflösung = 1680;
    int yauflösung = 1456;
    sf::RenderWindow window(sf::VideoMode(xauflösung, yauflösung), "SFML window");
    sf::View mView(sf::FloatRect(0, 0, xauflösung, yauflösung));
    window.setView(mView);
    
    sf::Vector2i test1;
 sf::Vector2f test2;
    sf::RectangleShape test;
    test.setSize(sf::Vector2f(10,10));
    test.setFillColor(sf::Color::White);
    
    test.setOrigin(10/2, 10/2);
                 
    Button<float> Button1(sf::Vector2f(xauflösung/2 - 150,100), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5, test2.x, test2.y);
    Button<float> Button2(sf::Vector2f(xauflösung/2 - 150,200), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,test2.x, test2.y);
    Button<float> Button3(sf::Vector2f(xauflösung/2 - 150,300), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,test2.x, test2.y);
    Button<float> Button4(sf::Vector2f(xauflösung/2 - 150,400), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,test2.x, test2.y);
   
    
    
    
    // Start the game loop
    while (window.isOpen())
    {
      
        test1.x = sf::Mouse::getPosition(window).x;
        test1.y = sf::Mouse::getPosition(window).y;
        
       
        test2 = window.mapPixelToCoords(test1);
        test.setPosition(test2.x, test2.y);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            Button1.update(event);
            Button2.update(event);
            Button3.update(event);
            Button4.update(event);
          
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
            
            if (sf::Event::Resized)
            {
                
                
            }
           
        }
       
        // Clear screen
        window.clear();
       
        Button1.render(window);
        Button2.render(window);
        Button3.render(window);
        Button4.render(window);
         window.draw(test);
      
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
