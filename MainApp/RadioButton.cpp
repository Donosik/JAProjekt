#include "RadioButton.h"

RadioButton::RadioButton(int width, int height, int xPos, int yPos, std::string text, sf::Font &font)
{
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;
    scale = 0.4f;
    clicked = sf::Color::Green;
    unclicked = sf::Color::Red;

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::Cyan);
    box.setRadius(height * scale);
    box.setPosition(xPos + ((0.5f - scale) * height), yPos + ((0.5f - scale) * height));
    box.setFillColor(unclicked);

    this->text.setFont(font);
    this->text.setPosition(xPos + height * scale * 2 + 20, yPos + 10);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(30);
    this->text.setString(text);

}

bool RadioButton::GetIsClicked()
{
    return isClicked;
}

bool RadioButton::CheckEvent(sf::Event event)
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

void RadioButton::Draw(sf::RenderWindow &window)
{

    window.draw(shape);
    window.draw(box);
    window.draw(text);
}

void RadioButton::SetClicked()
{
    isClicked = true;
    box.setFillColor(clicked);
}

void RadioButton::SetUnclicked()
{
    isClicked = false;
    box.setFillColor(unclicked);
}
