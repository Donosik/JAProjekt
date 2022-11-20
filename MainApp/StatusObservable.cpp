#include "StatusObservable.h"

void StatusObservable::NotifyAll(Status i)
{
    for(auto x:observers)
    {
        x->Update(i);
    }
}

void StatusObservable::AddObserver(IStatusObserver *x)
{
    observers.push_back(x);
}

void StatusObservable::DeleteObserver(IStatusObserver *x)
{
   observers.erase(std::remove(observers.begin(),observers.end(),x),observers.end());
}
