#ifndef MAINAPP_IMAGEBUTTON_H
#define MAINAPP_IMAGEBUTTON_H

#include <string>
#include <vector>
#include "IView.h"
#include "IStatusObserver.h"


class ImageButton : public IStatusObserver, public IView
{
    int width;
    int height;
    int xPos;
    int yPos;
    int choosen;
    std::vector<sf::Image> images;
    sf::Texture texture;
    sf::Sprite image;
public:
    ImageButton(int width, int height, int xPos, int yPos);

    void AddImage(sf::Image img);

    void SetImage(int i);

    sf::Image GetImage();

    void SetScale();

    virtual void Update(Status i) override;

    bool CheckEvent(sf::Event event) override;

    void Draw(sf::RenderWindow &window) override;
};


#endif MAINAPP_IMAGEBUTTON_H
