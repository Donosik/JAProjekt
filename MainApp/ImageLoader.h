#ifndef MAINAPP_IMAGELOADER_H
#define MAINAPP_IMAGELOADER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class ImageLoader
{
public:
    sf::Image GetImageFromFile(std::string fileName);
};


#endif MAINAPP_IMAGELOADER_H
