
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "CommandLine.h"
//#define NDEBUG
#include <cassert>
int main(int, char const**)
{
    // Create the main window
    int xauflösung = 1200;
    int yauflösung = 700;
    sf::RenderWindow window(sf::VideoMode(xauflösung, yauflösung), "SFML window");
	sf::Vector2f MousePos;
	sf::RectangleShape MouseRec;
	sf::Font mFont;
	CommandLine CmdLine;

	sf::View mView(sf::FloatRect(0, 0, xauflösung, yauflösung));
	window.setView(mView);
	MouseRec.setSize(sf::Vector2f(10, 10));
	MouseRec.setFillColor(sf::Color::White);
	MouseRec.setOrigin(10 / 2, 10 / 2);
	//OSX
	if (system("cls"))
	{
		CmdLine.setFont("/Users/Thomas/Desktop/Fertige Projekte/Nameles/Nameless/Nameless/sansation.ttf");
		mFont.loadFromFile("/Users/Thomas/Desktop/Fertige Projekte/Nameles/Nameless/Nameless/sansation.ttf");
	}
	
	//WINDOWS
	//Kleiner Hack um die Schrift auf Windows zu laden. Returned -1 da unbekannt und die Funtion wird aus-
	//geführt, auf mac ist der befehl bekannt und und sollte daher 0 returnen und die funktion nicht aufrufen	
	if (system("clear")) 
	{					
		CmdLine.setFont("C:\\Users\\Programming\\Documents\\GitHub\\Nameless2.0\\sansation.ttf");
		mFont.loadFromFile("C:\\Users\\Programming\\Documents\\GitHub\\Nameless2.0\\sansation.ttf");
	}
	


  
    Button<float> Button1(sf::Vector2f(xauflösung/2 - 150,100), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5, MousePos.x, MousePos.y, "Spielen", mFont);
    Button<float> Button2(sf::Vector2f(xauflösung/2 - 150,200), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,MousePos.x, MousePos.y, "Optionen", mFont);
    Button<float> Button3(sf::Vector2f(xauflösung/2 - 150,300), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,MousePos.x, MousePos.y, "Credits", mFont);
    Button<float> Button4(sf::Vector2f(xauflösung/2 - 150,400), 50,300, sf::Color::Red, sf::Color::Blue, mView, window,5,MousePos.x, MousePos.y, "Beenden", mFont);
   
  
    
    
    // Start the game loop
    while (window.isOpen())
    {
        MousePos = window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
        MouseRec.setPosition(MousePos.x, MousePos.y);
        
        
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            Button1.eventHandling(event);
            Button2.eventHandling(event);
            Button3.eventHandling(event);
            Button4.eventHandling(event);
			CmdLine.eventHandling(event);
          
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Espace pressed : exit
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || Button4.getStatus())
            {
                window.close();
            }
        }
       
        // Clear screen
        window.clear();
       
        Button1.render(window);
        Button2.render(window);
        Button3.render(window);
        Button4.render(window);
		CmdLine.render(window);
         window.draw(MouseRec);
      
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
