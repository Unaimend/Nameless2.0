#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

template <typename T> class Button
{
public:
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, float thickness);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture);
    Button(Button&) = delete;
    
    void render(sf::RenderWindow& window);
    void update(sf::Event& event);
    bool isClicked();
private:
    sf::RectangleShape  mRectangleShape;
    sf::Vector2f        mPos;
    sf::Texture         mTexture;
    sf::Event           mEvent;
    T                   mHeigth;
    T                   mWidth;
    bool                mIsClicked         =   0;
};
















































template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, float thickness):
mPos(topleft), mHeigth(heigth), mWidth(width)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
    std::cout << "HALLLO" << std::endl;
};




template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture):
mPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
    
    std::cout << "HALLLO" << std::endl;
};



template<typename T> void Button<T>::render(sf::RenderWindow& window)
{
    window.draw(mRectangleShape);
};



template<typename T> void Button<T>::update(sf::Event& event)
{
    mEvent = event;
    
};

template<typename T> bool Button<T>::isClicked()
{
    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        
    }
    
    return mIsClicked;
};



