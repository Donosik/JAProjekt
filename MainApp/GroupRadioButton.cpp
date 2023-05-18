#include "GroupRadioButton.h"

GroupRadioButton::GroupRadioButton(int width, int height, int xPos, int yPos, int offset, std::vector<std::string> texts, sf::Font &font,int statusOffset, bool isDown)
{
    for (int i = 0; i < texts.size(); i++)
    {
        if (isDown)
        {
            RadioButton radioButton = RadioButton(width, height, xPos, yPos + (i * (height + offset)), texts[i], font);
            radioButtons.push_back(radioButton);
        }
        else
        {
            RadioButton radioButton = RadioButton(width, height, xPos+ (i * (width + offset)), yPos, texts[i], font);
            radioButtons.push_back(radioButton);
        }
    }
    offSet=statusOffset;

}

bool GroupRadioButton::CheckEvent(sf::Event event)
{
    int choosen = -1;
    for (int i = 0; i < radioButtons.size(); i++)
    {
        if (radioButtons[i].CheckEvent(event))
        {
            choosen = i;
            break;
        }
    }

    if (choosen != -1)
    {
        for (int i = 0; i < radioButtons.size(); i++)
        {
            if (i == choosen)
            {
                radioButtons[i].SetClicked();
            }
            else
            {
                radioButtons[i].SetUnclicked();
            }
        }
        NotifyAll(static_cast<Status>(choosen+offSet));
    }
    return false;
}

void GroupRadioButton::Draw(sf::RenderWindow &window)
{
    for (auto x: radioButtons)
    {
        x.Draw(window);
    }
}