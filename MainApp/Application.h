#ifndef MAINAPP_APPLICATION_H
#define MAINAPP_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "WindowData.h"
#include "GroupRadioButton.h"
#include "LibraryWrapper.h"
#include "Button.h"
#include "ImageButton.h"
#include "ImageLoader.h"
#include "ResultImage.h"
#include "ShowTime.h"
#include "Slider.h"

class Application
{
    WindowData windowData;
    sf::RenderWindow mainWindow;
    sf::Font font;
    LibraryWrapper* libraryWrapper;
    std::vector<IView*> views;
    std::vector<sf::Image> images;

public:
    Application();
    void Initialize();
    void Run();
    void HandleEvents();
    void Draw();
};


#endif MAINAPP_APPLICATION_H
