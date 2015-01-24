#ifndef __Test__CommandLine__
#define __Test__CommandLine__

#include <stdio.h>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
class CommandLine
{
public:
	CommandLine();
    CommandLine(std::string font);
    ~CommandLine();
    void render(sf::RenderWindow& window);
    void eventHandling(sf::Event event);
	void setFont(std::string font)
	{
		mFont.loadFromFile(font);
		mText.setFont(mFont);
	};
private:
    bool mConsoleOpen = false;
    sf::Text                    mText;
    sf::Font                    mFont;
    sf::Event                   mEvent;
    std::vector<std::string>    Text;
    std::string                 textstring;
    sf::RenderWindow            *pRenderWindow;
    
    void ReturnPressed();
    int test = 5;
    std::string test2;
    
};
#endif /* defined(__Test__CommandLine__) */
