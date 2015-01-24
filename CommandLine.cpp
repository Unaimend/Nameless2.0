#include "CommandLine.h"

CommandLine::CommandLine()
{
    mFont.loadFromFile("/Developer/Python/pygame/Examples/data/sans.ttf");
    mText.setCharacterSize(20);
    mText.setFont(mFont);
    test2 = std::to_string(test);
    std::cout << test2 << std::endl;
};



CommandLine::~CommandLine()
{


};



void CommandLine::render(sf::RenderWindow &window)
{
    
    pRenderWindow = &window;
    window.draw(mText);
    
    
};



void CommandLine::eventHandling(sf::Event event)
{

    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
    {
        if (mConsoleOpen == false)
        {
            mConsoleOpen = true;
        }
        else
        {
            mConsoleOpen = false;
        }
      
    }
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
    {
        textstring.append("a");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B)
    {
        textstring.append("b");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
    {
        textstring.append("c");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        textstring.append("d");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
    {
        textstring.append("e");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F)
    {
        textstring.append("f");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G)
    {
        textstring.append("g");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H)
    {
        textstring.append("h");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
    {
        textstring.append("i");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J)
    {
        textstring.append("j");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K)
    {
        textstring.append("k");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
    {
        textstring.append("l");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
    {
        textstring.append("m");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N)
    {
        textstring.append("n");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O)
    {
        textstring.append("o");
    }if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        textstring.append("p");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
    {
        textstring.append("q");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
    {
        textstring.append("r");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
    {
        textstring.append("s");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
    {
        textstring.append("t");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U)
    {
        textstring.append("u");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V)
    {
        textstring.append("b");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
    {
        textstring.append("w");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
    {
        textstring.append("x");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Y)
    {
        textstring.append("y");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
    {
        textstring.append("z");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        textstring.append(" ");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num0)
    {
        textstring.append("1");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
    {
        textstring.append("2");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2)
    {
        textstring.append("3");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3)
    {
        textstring.append("4");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4)
    {
        textstring.append("5");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5)
    {
        textstring.append("6");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5)
    {
        textstring.append("7");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num6)
    {
        textstring.append("8");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num7)
    {
        textstring.append("9");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num8)
    {
        textstring.append("0");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num9)
    {
        textstring.append(" ");
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num0)
    {
        textstring.append(" ");
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    {
        ReturnPressed();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
    {
        if (textstring.length() != 0)
        {
            textstring.erase(textstring.end() - 1);
        }
        
    }
    mText.setString(textstring);
};



void CommandLine::ReturnPressed()
{
    if (textstring.find("quit") == 0)
    {
        pRenderWindow->close();
    }

    textstring.clear();
};