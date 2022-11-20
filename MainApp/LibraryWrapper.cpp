#include "LibraryWrapper.h"

LibraryWrapper::LibraryWrapper()
{
    if (LoadAsmDLL())
    {
        asmLoaded = true;
    }
    else
    {
        std::cout << "Nie załadowano ASM DLL" << std::endl;
        asmLoaded = false;
    }
    if (LoadCppDLL())
    {
        cppLoaded = true;
    }
    else
    {
        std::cout << "Nie załadowano CPP DLL" << std::endl;
        cppLoaded = false;
    }
    dlllibrary = NONE;
    threadNumber = 1;
}

void LibraryWrapper::UseFunction()
{
    ImageObservable::NotifyAll(choosenImage);
    sf::Clock clock;
    if (dlllibrary == ASM)
    {
        UseAsmFunction();
    }
    else if (dlllibrary == CPP)
    {
        UseCppFunction();
    }
    else if (dlllibrary == NONE)
    {
        return;
    }
    elapsed = clock.getElapsedTime();
    ImageObservable::NotifyAll(resultImage);
    TimeObservable::NotifyAll(elapsed);

}

void LibraryWrapper::SetImages(std::vector<sf::Image> img)
{
    images = img;
    choosenImage = images[0];
}

void LibraryWrapper::Update(Status i)
{

    switch (i)
    {
        case Status::ASMCHOOSED:
        {
            dlllibrary = ASM;
        }
            break;
        case Status::CPPCHOOSED:
        {
            dlllibrary = CPP;
        }
            break;
        case Status::START:
        {
            UseFunction();
        }
            break;
        case Status::CHANGETO1IMAGE:
        {
            choosenImage = images[0];
        }
            break;
        case Status::CHANGETO2IMAGE:
        {
            choosenImage = images[1];
        }
            break;
        case Status::CHANGETO3IMAGE:
        {
            choosenImage = images[2];
        }
            break;
        default:
        {
            std::cout << "Nie ma takiego statusu" << std::endl;
        }
    }
}


void LibraryWrapper::UseAsmFunction()
{
    if (asmLoaded)
    {
        resultImage = choosenImage;
        //std::cout << asmProc(20) << std::endl;
    }
}

void LibraryWrapper::UseCppFunction()
{
    if (cppLoaded)
    {
        resultImage = choosenImage;

        int i = 0;
        for (; (i + threadNumber) < choosenImage.getSize().x; i += threadNumber)
        {
            for(int j=0;j<threadNumber;j++)
            {
                CppInner cppInner;
                cppInner.SetValues(cppProc,choosenImage,i);
                std::promise<sf::Image> p;
                std::future<sf::Image>f=p.get_future();
                std::thread t(cppInner,std::move(p));
                threads.push_back(std::move(t));
                resultImage.copy(f.get(),i,0,sf::IntRect(i,0,1,choosenImage.getSize().y));
            }
        }
        for (; i < choosenImage.getSize().x; i++)
        {
            //CppInner(i);
        }

        choosenImage = resultImage;
    }
}


bool LibraryWrapper::LoadAsmDLL()
{

    asmLib = LoadLibrary(TEXT("DLL_ASM.dll"));
    if (asmLib != NULL)
    {
        asmProc = (MYPROC) GetProcAddress(asmLib, "FProc");
        if (NULL != asmProc)
        {
            return true;
        }
    }

    return false;
}

bool LibraryWrapper::LoadCppDLL()
{

    cppLib = LoadLibrary(TEXT("CppDll.dll"));
    if (cppLib != NULL)
    {
        cppProc = (MYPROC) GetProcAddress(cppLib, "dilatation");
        if (NULL != cppProc)
        {
            return true;
        }
    }

    return false;
}