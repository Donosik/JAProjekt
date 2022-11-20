#ifndef MAINAPP_STATUSOBSERVABLE_H
#define MAINAPP_STATUSOBSERVABLE_H

#include <vector>
#include "IStatusObserver.h"
#include "Status.h"

class StatusObservable
{
protected:
    std::vector<IStatusObserver*> observers;

    void NotifyAll(Status i);
public:
    void AddObserver(IStatusObserver* x);
    void DeleteObserver(IStatusObserver* x);
};


#endif MAINAPP_STATUSOBSERVABLE_H
