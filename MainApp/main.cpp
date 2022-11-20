#include "Application.h"

int main()
{
    try
    {
        Application application;
    }
    catch(std::exception ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}
