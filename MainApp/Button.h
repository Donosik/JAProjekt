#ifndef MAINAPP_BUTTON_H
#define MAINAPP_BUTTON_H

#include <string>
#include "IView.h"
#include "StatusObservable.h"

class Button : public StatusObservable, public IView
{
    int width;
    int height;
    int xPos;
    int yPos;
    sf::RectangleShape shape;
    sf::Text text;
    Status status;

public:
    Button(int width, int height, int xPos, int yPos, std::string text, sf::Font &font,Status status);

    bool CheckEvent(sf::Event event) override;

    void Draw(sf::RenderWindow &window) override;

};


#endif MAINAPP_BUTTON_H
