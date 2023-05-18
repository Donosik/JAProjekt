#include "ImageButton.h"

ImageButton::ImageButton(int width, int height, int xPos, int yPos)
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
    AddImage(img);
    SetImage(0);
}

void ImageButton::AddImage(sf::Image img)
{
    images.push_back(img);
}

void ImageButton::SetImage(int i)
{
    if (i < images.size())
    {
        choosen=i;
        texture.loadFromImage(images[i]);
        image=sf::Sprite();
        image.setTexture(texture);
        image.setPosition(xPos, yPos);
        SetScale();
    }
}

sf::Image ImageButton::GetImage()
{
    return images[choosen];
}

void ImageButton::SetScale()
{

    sf::Vector2u imgSize = images[choosen].getSize();
    float xSize = (float)width/imgSize.x;
    float ySize = (float)height/imgSize.y;

    float scale = 1;
    image.setScale(xSize * scale, ySize * scale);
}


void ImageButton::Update(Status i)
{
    switch (i)
    {
        case Status::CHANGETO1IMAGE:
        {
            SetImage(1);
        }
            break;
        case Status::CHANGETO2IMAGE:
        {
            SetImage(2);
        }
            break;
        case Status::CHANGETO3IMAGE:
        {
            SetImage(3);
        }
            break;
    }
}

bool ImageButton::CheckEvent(sf::Event event)
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

void ImageButton::Draw(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(image);
}
