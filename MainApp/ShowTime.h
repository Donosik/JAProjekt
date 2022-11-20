#ifndef MAINAPP_SHOWTIME_H
#define MAINAPP_SHOWTIME_H

#include "IView.h"
#include "ITimeObserver.h"

class ShowTime:public IView,public ITimeObserver
{
    int width;
    int height;
    int xPos;
    int yPos;
    sf::Text text;
public:
    ShowTime(int width, int height, int xPos, int yPos, std::string text, sf::Font &font);

    void SetTime(std::string time);

    virtual void Update(sf::Time time) override;

    bool CheckEvent(sf::Event event) override;

    void Draw(sf::RenderWindow &window) override;
};


#endif MAINAPP_SHOWTIME_H
