#ifndef MAINAPP_ITIMEOBSERVER_H
#define MAINAPP_ITIMEOBSERVER_H

#include <SFML/Graphics.hpp>

class ITimeObserver
{
public:
    virtual void Update(sf::Time time)=0;
};

#endif MAINAPP_ITIMEOBSERVER_H
