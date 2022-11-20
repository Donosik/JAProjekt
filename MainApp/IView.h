#ifndef MAINAPP_IVIEW_H
#define MAINAPP_IVIEW_H

#include <SFML/Graphics.hpp>

class IView
{
public:
    virtual bool CheckEvent(sf::Event event) = 0;

    virtual void Draw(sf::RenderWindow &window) = 0;
};

#endif MAINAPP_IVIEW_H
