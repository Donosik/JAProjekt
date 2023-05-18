#ifndef MAINAPP_GROUPRADIOBUTTON_H
#define MAINAPP_GROUPRADIOBUTTON_H

#include <vector>
#include "RadioButton.h"
#include "StatusObservable.h"

class GroupRadioButton : public StatusObservable, public IView
{
    std::vector<RadioButton> radioButtons;
    int offSet;
public:
    GroupRadioButton(int width,int height,int xPos,int yPos,int offset,std::vector<std::string> texts,sf::Font& font,int statusOffset,bool isDown=true);
    bool CheckEvent(sf::Event event) override;
    void Draw(sf::RenderWindow& window) override;
};


#endif MAINAPP_GROUPRADIOBUTTON_H
