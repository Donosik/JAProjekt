#include "Button.h"

Button::Button(int width, int height, int xPos, int yPos, std::string text, sf::Font &font, Status status)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;
    this->status = status;

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::Cyan);

    this->text.setFont(font);
    this->text.setPosition(xPos + 10, yPos + 10);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(30);
    this->text.setString(text);

}

bool Button::CheckEvent(sf::Event event)
{
    if ((event.mouseButton.x >= xPos) && (event.mouseButton.x <= xPos + width) && (event.mouseButton.y >= yPos) && (event.mouseButton.y <= yPos + height))
    {
        NotifyAll(status);
        return true;
    }
    else
    {
        return false;
    }
}

void Button::Draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}
