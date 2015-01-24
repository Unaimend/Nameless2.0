#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>

template <typename T> class Button
{
public:
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, sf::View &view, sf::RenderWindow &window ,float thickness, float &xcheck, float& ycheck);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Color outline, sf::Color fill, sf::View &view, sf::RenderWindow &window ,float thickness, float &xcheck, float& ycheck, std::string string, sf::Font font);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture, sf::View &view, sf::RenderWindow &window, float &xcheck, float& ycheck);
    Button(sf::Vector2f topleft, T width, T heigth, sf::Texture texture, sf::View &view, sf::RenderWindow &window, float &xceck, float &ycheck, std::string string, sf::Font font);
    Button(Button&) = delete;                       //Copy-Constructor deleted, because of unwanted copies
    
    void render(sf::RenderWindow& window);
    void eventHandling(sf::Event& event);
    void update(float frametime);
    void setWindow(sf::RenderWindow& window){mWindow = &window;};
    bool isClicked();
    bool getStatus(){return mIsClicked;};
private:
    sf::RectangleShape  mRectangleShape;
    sf::Vector2f        mButPos;                       //Button Position.
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
    sf::Font            mFont;
    sf::Text            mText;                      //Text of the Button
    sf::FloatRect       mTextGloBounds;
};
















































template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, sf::View &view,
                                       sf::RenderWindow &window, float thickness,float &xcheck, float& ycheck):
mButPos(topleft), mHeigth(heigth), mWidth(width), mView(&view), mWindow(&window), mToCheckX(&xcheck), mToCheckY(&ycheck)
{
    mRectangleShape.setPosition(mButPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
    mString = "";
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Color outline, sf::Color fill, sf::View &view,
                                       sf::RenderWindow &window, float thickness, float &xcheck, float& ycheck, std::string string, sf::Font font ):
mButPos(topleft), mHeigth(heigth), mWidth(width), mView(&view), mWindow(&window), mToCheckX(&xcheck), mToCheckY(&ycheck) ,mString(string), mFont(font)
{
    mRectangleShape.setPosition(mButPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setOutlineThickness(thickness);
    mRectangleShape.setFillColor(fill);
    mRectangleShape.setOutlineColor(outline);
    
    
    mText.setString(mString);
    mText.setFont(mFont);
    mText.setCharacterSize(200);
    mText.setScale(0.075*2, 0.075*2);
    
    mTextGloBounds = mText.getGlobalBounds();
    mText.setOrigin(mTextGloBounds.left/2, mTextGloBounds.height/2);
    mText.setPosition(mButPos.x, mButPos.y);
    
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture, sf:: View &view,
                                       sf::RenderWindow &window, float &xcheck, float& ycheck):
mButPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture), mView(&view), mWindow(&window), mToCheckX(&xcheck), mToCheckY(&ycheck)

{
    mRectangleShape.setPosition(mButPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
    mString = "";
};



template<typename T> Button<T>::Button(sf::Vector2f topleft, T heigth, T width, sf::Texture texture, sf:: View &view,
                                       sf::RenderWindow &window, float &xckeck, float &ycheck ,std::string string, sf::Font font ):
mButPos(topleft), mHeigth(heigth), mWidth(width), mTexture(texture), mView(&view), mWindow(&window), mToCheckX(&xckeck), mToCheckY(&ycheck),mString(string), mFont(font)
{
    mRectangleShape.setPosition(mButPos);
    mRectangleShape.setSize(sf::Vector2f(mWidth,mHeigth));
    mRectangleShape.setTexture(&mTexture);
    
    mText.setFont(mFont);
    mText.setCharacterSize(20);
    mText.setString(mString);
};



template<typename T> void Button<T>::render(sf::RenderWindow& window)
{
    window.draw(mRectangleShape);
    window.draw(mText);
    
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
      
        if ((*mToCheckY > mButPos.y) &&
            (*mToCheckY < mButPos.y + mHeigth))
        {
            if ((*mToCheckX > mButPos.x) &&
                (*mToCheckX < mButPos.x + mWidth))
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
   
    return mIsClicked;
};



