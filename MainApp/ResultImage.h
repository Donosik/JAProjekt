#ifndef MAINAPP_RESULTIMAGE_H
#define MAINAPP_RESULTIMAGE_H

#include <SFML/Graphics.hpp>
#include "IView.h"
#include "IImageObserver.h"

class ResultImage : public IImageObserver,public IView
{
    int width;
    int height;
    int xPos;
    int yPos;
    sf::Image img;
    sf::Texture texture;
    sf::Sprite image;
    sf::RectangleShape background;
    int frameWidth;
public:
    ResultImage(int width, int height, int xPos, int yPos);
    void SetScale();
    void SetImage(sf::Image img);
    virtual void Update(sf::Image image) override;
    bool CheckEvent(sf::Event event) override;

    void Draw(sf::RenderWindow &window) override;
};


#endif MAINAPP_RESULTIMAGE_H
