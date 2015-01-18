#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

template <typename T> class Button
{
public:
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, sf::View view, sf::Window &window ,float thickness);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture, sf::View view, sf::Window &window);
    Button(Button&) = delete;                       //Copy-Constructor deleted, because of unwanted copies
    
    void render(sf::RenderWindow& window);
    void update(sf::Event& event);
    void update(float frametime);
    bool isClicked();
private:
    sf::RectangleShape  mRectangleShape;
    sf::Vector2f        mPos;                       //Button Position.
    sf::Texture         mTexture;                   //Texture of the button, if it has one.
    sf::Event           mEvent;                     //Is mouse clicked?
    sf::View            mView;
    sf::Window         *mWindow;
    T                   mHeigth;                    //Height of the Button
    T                   mWidth;                     //Width of the Button
    bool                mIsClicked         =   0;
};
















































template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, sf::View view,
                                       sf::Window &window, float thickness):
mPos(topleft), mHeigth(heigth), mWidth(width), mView(view), mWindow(&window)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
};




template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture, sf:: View view,
                                       sf::Window &window ):
mPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture), mView(view), mWindow(&window)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
};



template<typename T> void Button<T>::render(sf::RenderWindow& window)
{
    window.draw(mRectangleShape);
};



template<typename T> void Button<T>::update(sf::Event& event)
{
    mEvent = event;
    isClicked();
    
};

template<typename T> bool Button<T>::isClicked()
{
    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if ((sf::Mouse::getPosition(*mWindow).y > mPos.y) &&
            (sf::Mouse::getPosition(*mWindow).y < mPos.y + mHeigth))
        {
            if ((sf::Mouse::getPosition(*mWindow).x > mPos.x) &&
                (sf::Mouse::getPosition(*mWindow).x < mPos.x + mWidth))
            {
                mIsClicked = true;
                
            }
            else
            {
                mIsClicked = false;
            }
        }
        else
        {
            mIsClicked = false;
        }
    }
    std::cout << mIsClicked << std::endl;
    return mIsClicked;
};



