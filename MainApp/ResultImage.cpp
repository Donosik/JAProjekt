#include "ResultImage.h"

ResultImage::ResultImage(int width, int height, int xPos, int yPos)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;

    frameWidth=2;

    background.setPosition(xPos - frameWidth, yPos - frameWidth);
    background.setSize(sf::Vector2f(width + 2*frameWidth, height + 2*frameWidth));
    background.setFillColor(sf::Color::Green);

    sf::Image img;
    img.create(width,height,sf::Color::Black);
    SetImage(img);
}

void ResultImage::SetScale()
{
    sf::Vector2u imgSize = img.getSize();
    float xSize = (float) width / imgSize.x;
    float ySize = (float) height / imgSize.y;

    float scale = 1;
    image.setScale(xSize * scale, ySize * scale);
}

void ResultImage::SetImage(sf::Image img)
{

    this->img = img;
    texture.loadFromImage(img);
    image = sf::Sprite();
    image.setTexture(texture);
    image.setPosition(xPos, yPos);
    SetScale();
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
    window.draw(background);
    window.draw(image);
}


