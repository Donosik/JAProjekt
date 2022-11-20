#ifndef MAINAPP_IIMAGEOBSERVER_H
#define MAINAPP_IIMAGEOBSERVER_H

#include <SFML/Graphics.hpp>

class IImageObserver
{
public:
    virtual void Update(sf::Image image)=0;
};

#endif MAINAPP_IIMAGEOBSERVER_H
