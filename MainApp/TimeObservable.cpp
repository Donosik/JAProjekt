#include "TimeObservable.h"

void TimeObservable::NotifyAll(sf::Time time)
{
    for(auto x:observers)
    {
        x->Update(time);
    }
}

void TimeObservable::AddObserver(ITimeObserver *x)
{
    observers.push_back(x);
}

void TimeObservable::DeleteObserver(ITimeObserver *x)
{
    observers.erase(std::remove(observers.begin(),observers.end(),x),observers.end());
}