#ifndef MAINAPP_ISTATUSOBSERVER_H
#define MAINAPP_ISTATUSOBSERVER_H

#include "Status.h"

class IStatusObserver
{
public:
    virtual void Update(Status i)=0;
};

#endif MAINAPP_ISTATUSOBSERVER_H
