#ifndef MAINAPP_SLIDER_H
#define MAINAPP_SLIDER_H

#include "IView.h"
#include "StatusObservable.h"

class Slider : public StatusObservable,public IView
{
    int width;
    int xPos;
    int yPos;
    sf::RectangleShape axis;
    sf::RectangleShape slider;
    sf::Font font;
    sf::Text values[7];
    int sliderValue;

public:
    Slider(int width,int xPos,int yPos,sf::Font &font,int threadNumber);

    bool CheckEvent(sf::Event event) override;

    void Draw(sf::RenderWindow &window) override;

private:
    void SetValue(int x);
};


#endif MAINAPP_SLIDER_H
