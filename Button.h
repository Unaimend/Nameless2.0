#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>
template <typename T> class Button
{
public:
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, sf::View &view, sf::RenderWindow &window ,float thickness, float &xcheck, float& ycheck);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, sf::View &view, sf::RenderWindow &window ,float thickness, std::string string);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture, sf::View &view, sf::RenderWindow &window);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture, sf::View &view, sf::RenderWindow &window, std::string string);
    Button(Button&) = delete;                       //Copy-Constructor deleted, because of unwanted copies
    
    void render(sf::RenderWindow& window);
    void eventHandling(sf::Event& event);
    void update(float frametime);
    void setWindow(sf::RenderWindow& window){mWindow = &window;};
    bool isClicked();
private:
    sf::RectangleShape  mRectangleShape;
    sf::Vector2f        mPos;                       //Button Position.
    sf::Texture         mTexture;                   //Texture of the button, if it has one.
    sf::Event           mEvent;                     //Is mouse clicked?
    sf::View            *mView;
    sf::RenderWindow    *mWindow;
    float               *mToCheckX;                 //Holds mouse coordinates
    float               *mToCheckY;
    T                   mHeigth;                    //Height of the Button
    T                   mWidth;                     //Width of the Button
    bool                mIsClicked         =   0;   //True if Button was clicked, should be true for one frame
    std::string         mString;
    sf::Text            mText;                      //Text of the Button
};
















































template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, sf::View &view,
                                       sf::RenderWindow &window, float thickness,float &xcheck, float& ycheck):
mPos(topleft), mHeigth(heigth), mWidth(width), mView(&view), mWindow(&window), mToCheckX(&xcheck), mToCheckY(&ycheck)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
    mString = "";
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, sf::View &view,
                                       sf::RenderWindow &window, float thickness, std::string string):
mPos(topleft), mHeigth(heigth), mWidth(width), mView(&view), mWindow(&window), mString(string)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
    
    mText.setString(mString);
    
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture, sf:: View &view,
                                       sf::RenderWindow &window ):
mPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture), mView(&view), mWindow(&window)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
    mString = "";
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture, sf:: View &view,
                                       sf::RenderWindow &window, std::string string ):
mPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture), mView(&view), mWindow(&window), mString(string)
{
    mRectangleShape.setPosition(mPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
    
    mText.setString(mString);
    
};



template<typename T> void Button<T>::render(sf::RenderWindow& window)
{
    window.draw(mRectangleShape);
    
};



template<typename T> void Button<T>::eventHandling(sf::Event& event)
{
    mEvent = event;
    isClicked();
    
};



template<typename T> bool Button<T>::isClicked()
{
    if (mEvent.type == sf::Event::MouseButtonPressed && mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if ((*mToCheckY > mPos.y) &&
            (*mToCheckY < mPos.y + mHeigth))
        {
            if ((*mToCheckX > mPos.x) &&
                (*mToCheckX < mPos.x + mWidth))
            {
                mIsClicked = true;
                 std::cout << "PETER"<< std::endl;
                
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
   
    return mIsClicked;
};



