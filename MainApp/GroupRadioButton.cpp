#include "GroupRadioButton.h"

GroupRadioButton::GroupRadioButton(int width, int height, int xPos, int yPos, int offset, std::vector<std::string> texts,sf::Font& font)
{
    for(int i=0;i<texts.size();i++)
    {
        RadioButton radioButton=RadioButton(width,height,xPos,yPos+(i*(height+offset)),texts[i],font);
        radioButtons.push_back(radioButton);
    }

}

bool GroupRadioButton::CheckEvent(sf::Event event)
{
    int choosen=-1;
     for(int i=0;i<radioButtons.size();i++)
     {
         if(radioButtons[i].CheckEvent(event))
         {
             choosen=i;
             break;
         }
     }

     if(choosen!=-1)
     {
         for(int i=0;i<radioButtons.size();i++)
         {
             if(i==choosen)
             {
                 radioButtons[i].SetClicked();
             }
             else
             {
                 radioButtons[i].SetUnclicked();
             }
         }
         if(choosen==0)
         {
             NotifyAll(Status::ASMCHOOSED);
         }
         else if(choosen==1)
         {
             NotifyAll(Status::CPPCHOOSED);
         }
     }
     return false;
}

void GroupRadioButton::Draw(sf::RenderWindow &window)
{
    for(auto x : radioButtons)
    {
        x.Draw(window);
    }
}