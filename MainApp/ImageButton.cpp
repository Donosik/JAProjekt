#include "ImageButton.h"

ImageButton::ImageButton(int width, int height, int xPos, int yPos)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;

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
        image.setTexture(texture);
        image.setPosition(xPos, yPos);

    }
}

sf::Image ImageButton::GetImage()
{
    return images[choosen];
}

void ImageButton::SetScale()
{
    sf::Vector2u imgSize = images[0].getSize();

    float xSize = (float) width / imgSize.x;
    float ySize = (float) height / imgSize.y;
    image.scale(xSize, ySize);
}


void ImageButton::Update(Status i)
{
    switch (i)
    {
        case Status::CHANGETO1IMAGE:
        {
            SetImage(0);
        }
            break;
        case Status::CHANGETO2IMAGE:
        {
            SetImage(1);
        }
            break;
        case Status::CHANGETO3IMAGE:
        {
            SetImage(2);
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
    window.draw(image);
}
