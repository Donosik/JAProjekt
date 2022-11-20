#ifndef MAINAPP_TIMEOBSERVABLE_H
#define MAINAPP_TIMEOBSERVABLE_H

#include <vector>
#include "ITimeObserver.h"

class TimeObservable
{
protected:
    std::vector<ITimeObserver*> observers;
    void NotifyAll(sf::Time time);
public:
    void AddObserver(ITimeObserver* x);
    void DeleteObserver(ITimeObserver* x);
};


#endif MAINAPP_TIMEOBSERVABLE_H
