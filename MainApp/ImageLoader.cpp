#include "ImageLoader.h"

sf::Image ImageLoader::GetImageFromFile(std::string fileName)
{
    sf::Image image;

    if (image.loadFromFile(fileName))
    {
        bool isMonochromatic = true;

        for (int i = 0; i < image.getSize().x; i++)
        {
            for (int j = 0; j < image.getSize().y; j++)
            {
                sf::Color color = image.getPixel(i, j);
                if (color == sf::Color::White)
                {
                    continue;
                }
                else if (color == sf::Color::Black)
                {
                    continue;
                }
                else
                {

                    std::cout << "Obrazek nie jest monochromatyczny" << std::endl;
                    image.create(image.getSize().x, image.getSize().y, sf::Color::White);
                    isMonochromatic = false;
                    break;
                }
            }
            if (isMonochromatic == false)
            {
                break;
            }
        }
    }
    else
    {
        image.create(1920,1080,sf::Color::Yellow);
    }

    return image;
}
