#ifndef MAINAPP_LIBRARYWRAPPER_H
#define MAINAPP_LIBRARYWRAPPER_H

#define NOMINMAX

#include <windows.h>
#include <iostream>
#include <thread>
#include <future>
#include "ImageObservable.h"
#include "IStatusObserver.h"
#include "TimeObservable.h"


typedef int(__cdecl *MYPROC)(int, int, int, int, int, int, int, int);

enum DLLLIBRARY
{
    NONE,
    ASM,
    CPP
};

class CppInner
{
public:
    void operator()(std::promise<sf::Image> &&result)
    {
        sf::Image resultImage = choosenImage;
        int array[8];
        for (int j = 0; j < choosenImage.getSize().y; j++)
        {
            if ((i == 0) || (j == 0) || (i == (choosenImage.getSize().x - 1)) || (j == (choosenImage.getSize().y - 1)))
            {
                resultImage.setPixel(i, j, sf::Color::White);
            }
            else
            {
                array[0] = ConvertColorToInt(choosenImage.getPixel(i - 1, j - 1));
                array[1] = ConvertColorToInt(choosenImage.getPixel(i - 1, j));
                array[2] = ConvertColorToInt(choosenImage.getPixel(i - 1, j + 1));
                array[3] = ConvertColorToInt(choosenImage.getPixel(i, j - 1));
                array[4] = ConvertColorToInt(choosenImage.getPixel(i, j + 1));
                array[5] = ConvertColorToInt(choosenImage.getPixel(i + 1, j - 1));
                array[6] = ConvertColorToInt(choosenImage.getPixel(i + 1, j));
                array[7] = ConvertColorToInt(choosenImage.getPixel(i + 1, j + 1));

                if (cppProc(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7]) == 1)
                {

                    resultImage.setPixel(i, j, sf::Color::Black);
                }
                else
                {
                    resultImage.setPixel(i, j, sf::Color::White);
                }
            }
        }
        result.set_value(resultImage);
    }

    MYPROC cppProc;
    sf::Image choosenImage;
    int i;

    void SetValues(MYPROC cppProc, sf::Image choosenImage, int i)
    {
        this->i=i;
        this->choosenImage=choosenImage;
        this->cppProc=cppProc;
    }

    int ConvertColorToInt(sf::Color color)
    {
        if (color == sf::Color::White)
        {
            return 0;
        }
        else if (color == sf::Color::Black)
        {
            return 1;
        }
        return 2;
    }
};

class LibraryWrapper : public ImageObservable, public TimeObservable, public IStatusObserver
{
    HINSTANCE asmLib;
    HINSTANCE cppLib;
    MYPROC asmProc;
    MYPROC cppProc;
    DLLLIBRARY dlllibrary;
    bool asmLoaded;
    bool cppLoaded;
    std::vector<sf::Image> images;
    sf::Image choosenImage;
    sf::Image resultImage;
    sf::Time elapsed;
    std::vector<std::thread> threads;
    int threadNumber;
public:
    LibraryWrapper();

    void UseFunction();

    void SetImages(std::vector<sf::Image> img);

    virtual void Update(Status i) override;

private:
    void UseAsmFunction();

    void UseCppFunction();

    bool LoadAsmDLL();

    bool LoadCppDLL();
};


#endif MAINAPP_LIBRARYWRAPPER_H
