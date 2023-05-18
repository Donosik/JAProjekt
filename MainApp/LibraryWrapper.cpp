#include "LibraryWrapper.h"

LibraryWrapper::LibraryWrapper(int threadNumber)
{
    SetThreadNumber(threadNumber);
    name="dilatation";
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
}

void LibraryWrapper::SetThreadNumber(int x)
{
    threadNumber = x;
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
        case Status::THREAD1:
        {
            SetThreadNumber(1);
        }
            break;
        case Status::THREAD2:
        {
            SetThreadNumber(2);
        }
            break;
        case Status::THREAD4:
        {
            SetThreadNumber(4);
        }
            break;
        case Status::THREAD8:
        {
            SetThreadNumber(8);
        }
            break;
        case Status::THREAD16:
        {
            SetThreadNumber(16);
        }
            break;
        case Status::THREAD32:
        {
            SetThreadNumber(32);
        }
            break;
        case Status::THREAD64:
        {
            SetThreadNumber(64);
        }
            break;
        case Status::EROSION:
        {
            ChooseFunction("erosion");
        }
            break;
        case Status::DILATATION:
        {
            ChooseFunction("dilatation");
        }
            break;
        default:
        {
            std::cout << "Nie ma takiego statusu" << std::endl;
        }
    }
}

void LibraryWrapper::ChooseFunction(std::string name)
{
    this->name=name;
    if(dlllibrary==ASM)
    {
        LoadAsmDLL();
    }
    else if(dlllibrary==CPP)
    {
        LoadCppDLL();
    }
}

void LibraryWrapper::UseAsmFunction()
{
    if (asmLoaded)
    {
        resultImage = choosenImage;

        std::vector<std::future<sf::Image>> processedVector;
        int i = 0;
        for (; (i + threadNumber) < choosenImage.getSize().x; i += threadNumber)
        {
            for (int j = 0; j < threadNumber; j++)
            {
                processedVector.push_back(std::async(InnerLoop(), asmProc, choosenImage, i + j));
            }
            for (int j = 0; j < threadNumber; j++)
            {
                sf::IntRect r(i + j, 0, 1, choosenImage.getSize().y);
                resultImage.copy(processedVector[j].get(), i + j, 0, r);
            }
            processedVector.clear();
        }
        for (; i < choosenImage.getSize().x; i++)
        {
            auto future = std::async(InnerLoop(), asmProc, choosenImage, i);
            sf::Image processed = future.get();
            sf::IntRect r(i, 0, 1, choosenImage.getSize().y);
            resultImage.copy(processed, i, 0, r);

        }
        choosenImage = resultImage;
    }
}

void LibraryWrapper::UseCppFunction()
{
    if (cppLoaded)
    {
        resultImage = choosenImage;

        std::vector<std::future<sf::Image>> processedVector;
        int i = 0;
        for (; (i + threadNumber) < choosenImage.getSize().x; i += threadNumber)
        {
            for (int j = 0; j < threadNumber; j++)
            {
                processedVector.push_back(std::async(InnerLoop(), cppProc, choosenImage, i + j));
            }
            for (int j = 0; j < threadNumber; j++)
            {
                sf::IntRect r(i + j, 0, 1, choosenImage.getSize().y);
                resultImage.copy(processedVector[j].get(), i + j, 0, r);
            }
            processedVector.clear();
        }
        for (; i < choosenImage.getSize().x; i++)
        {
            auto future = std::async(InnerLoop(), cppProc, choosenImage, i);
            sf::Image processed = future.get();
            sf::IntRect r(i, 0, 1, choosenImage.getSize().y);
            resultImage.copy(processed, i, 0, r);

        }
        choosenImage = resultImage;
    }
}

bool LibraryWrapper::LoadAsmDLL()
{
    asmLib = LoadLibrary(TEXT("JAAsm.dll"));
    if (asmLib != NULL)
    {
        asmProc = (MYPROC) GetProcAddress(asmLib, name.c_str());
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
        cppProc = (MYPROC) GetProcAddress(cppLib, name.c_str());
        if (NULL != cppProc)
        {
            return true;
        }
    }

    return false;
}