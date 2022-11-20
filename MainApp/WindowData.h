#ifndef MAINAPP_WINDOWDATA_H
#define MAINAPP_WINDOWDATA_H

#include <string>

class WindowData
{
public:
    int height;
    int width;
    std::string name;
    WindowData()
    {
        height=720;
        width=1280;
        name="Operacje Morfologiczne";
    }
};

#endif MAINAPP_WINDOWDATA_H
