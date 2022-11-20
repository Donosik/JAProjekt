#include "ResultImage.h"

ResultImage::ResultImage(int width, int height, int xPos, int yPos)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;

}

#include <iostream>

void ResultImage::SetScale()
{
    sf::Vector2u imgSize = img.getSize();

    float xSize = (float) width / imgSize.x;
    float ySize = (float) height / imgSize.y;

    std::cout<<imgSize.x<<","<<imgSize.y<<std::endl;
    std::cout<<xSize<<","<<ySize<<std::endl;

    image.scale(xSize, ySize);
}

void ResultImage::SetImage(sf::Image img)
{

    this->img = img;
    texture.loadFromImage(img);
    image.setTexture(texture);
    image.setPosition(xPos, yPos);
    //image.setScale(1,1);
    //SetScale();
}

void ResultImage::Update(sf::Image image)
{
    SetImage(image);
}

bool ResultImage::CheckEvent(sf::Event event)
{
    if ((event.mouseButton.x >= xPos) && (event.mouseButton.x <= xPos + width) && (event.mouseButton.y >= yPos) && (event.mouseButton.y <= yPos + height))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ResultImage::Draw(sf::RenderWindow &window)
{
    window.draw(image);
}


