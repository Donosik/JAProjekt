#ifndef MAINAPP_RADIOBUTTON_H
#define MAINAPP_RADIOBUTTON_H

#include <string>
#include "IView.h"

class RadioButton : public IView
{
    int width;
    int height;
    int xPos;
    int yPos;
    float scale;
    bool isClicked;
    sf::RectangleShape shape;
    sf::CircleShape box;
    sf::Text text;
    sf::Color clicked;
    sf::Color unclicked;
public:
    RadioButton(int width,int height,int xPos,int yPos,std::string text,sf::Font& font);
    bool GetIsClicked();
    bool CheckEvent(sf::Event event) override;
    void Draw(sf::RenderWindow& window) override;

    void SetClicked();
    void SetUnclicked();
};


#endif MAINAPP_RADIOBUTTON_H
