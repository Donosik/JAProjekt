#include "Slider.h"

Slider::Slider(int width, int xPos, int yPos, sf::Font &font, int threadNumber)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->font = font;
    for (int i = 0; i < 7; i++)
    {
        values[i].setFont(this->font);
        int value = pow(2, i);
        values[i].setString(std::to_string(value));
        values[i].setCharacterSize(20);
        values[i].setFillColor(sf::Color::Yellow);
        values[i].setPosition(xPos + 10 + (i * 30), yPos + 30);
    }
    axis.setPosition(xPos, yPos);
    axis.setSize(sf::Vector2f(width, 20));
    axis.setFillColor(sf::Color::Blue);

    slider.setSize(sf::Vector2f(10, 40));
    slider.setFillColor(sf::Color::Red);
    SetValue(threadNumber);
}

bool Slider::CheckEvent(sf::Event event)
{
    for (int i = 0; i < 7; i++)
    {
        if ((event.mouseButton.y>yPos-10)&&(event.mouseButton.y<yPos+50))
        {
            if ((event.mouseButton.x > (xPos + ((i * 30) ))) && ((event.mouseButton.x < (xPos + ((i * 30) + 30)))))
            {
                int value = pow(2, i);
                SetValue(value);
            }
        }
    }
    return false;
}

void Slider::Draw(sf::RenderWindow &window)
{
    window.draw(axis);
    window.draw(values[0]);
    window.draw(values[1]);
    window.draw(values[2]);
    window.draw(values[3]);
    window.draw(values[4]);
    window.draw(values[5]);
    window.draw(values[6]);
    window.draw(slider);
}

void Slider::SetValue(int x)
{

    int value = 1;
    for (int i = 0; i < 7; i++)
    {
        value = pow(2, i);
        if (x == value)
        {
            slider.setPosition(xPos + 10 + (i * 30), yPos - 10);
            NotifyAll(static_cast<Status>(i + 6));
            return;
        }
    }

    slider.setPosition(xPos + 10, yPos - 1);
}
