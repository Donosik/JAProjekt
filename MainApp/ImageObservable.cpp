#include "ImageObservable.h"

void ImageObservable::NotifyAll(sf::Image image)
{
    for(auto x:observers)
    {
        x->Update(image);
    }
}

void ImageObservable::AddObserver(IImageObserver *x)
{
    observers.push_back(x);
}

void ImageObservable::DeleteObserver(IImageObserver *x)
{
    observers.erase(std::remove(observers.begin(),observers.end(),x),observers.end());
}