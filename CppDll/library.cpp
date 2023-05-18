#include "library.h"

int dilatation(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8)
{
    if(x1==1)
    {
        return 1;
    }
    else if(x2==1)
    {
        return 1;
    }
    else if(x3==1)
    {
        return 1;
    }
    else if(x4==1)
    {
        return 1;
    }
    else if(x5==1)
    {
        return 1;
    }
    else if(x6==1)
    {
        return 1;
    }
    else if(x7==1)
    {
        return 1;
    }
    else if(x8==1)
    {
        return 1;
    }
    return 0;
}
int erosion(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8)
{
    if (x1 == 0)
    {
        return 0;
    }
    else if (x2 == 0)
    {
        return 0;
    }
    else if (x3 == 0)
    {
        return 0;
    }
    else if (x4 == 0)
    {
        return 0;
    }
    else if (x5 == 0)
    {
        return 0;
    }
    else if (x6 == 0)
    {
        return 0;
    }
    else if (x7 == 0)
    {
        return 0;
    }
    else if (x8 == 0)
    {
        return 0;
    }
    return 1;
}