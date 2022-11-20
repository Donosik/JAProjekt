#ifndef MAINAPP_IMAGEOBSERVABLE_H
#define MAINAPP_IMAGEOBSERVABLE_H

#include <vector>
#include "IImageObserver.h"

class ImageObservable
{
protected:
    std::vector<IImageObserver*> observers;
    void NotifyAll(sf::Image image);
public:
    void AddObserver(IImageObserver* x);
    void DeleteObserver(IImageObserver* x);
};


#endif MAINAPP_IMAGEOBSERVABLE_H
