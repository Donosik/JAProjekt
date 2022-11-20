#include "ShowTime.h"

ShowTime::ShowTime(int width, int height, int xPos, int yPos, std::string text, sf::Font &font)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;

    this->text.setFont(font);
    this->text.setPosition(xPos, yPos);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    this->text.setString(text);
}

void ShowTime::SetTime(std::string time)
{
    text.setString(time+" us");
}

void ShowTime::Update(sf::Time time)
{
    SetTime(std::to_string(time.asMicroseconds()));
}

bool ShowTime::CheckEvent(sf::Event event)
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

void ShowTime::Draw(sf::RenderWindow &window)
{
    window.draw(text);
}
