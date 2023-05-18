#include "Application.h"

Application::Application()
{
    Initialize();
    Run();
}

void Application::Initialize()
{
    mainWindow.create(sf::VideoMode(windowData.width, windowData.height), windowData.name, sf::Style::Titlebar | sf::Style::Close);

    std::vector<std::string> texts;
    texts.push_back("Asm");
    texts.push_back("C++");

    std::vector<std::string> functionNames;
    functionNames.push_back("Erosion");
    functionNames.push_back("Dilatation");

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error occured during loading the font" << std::endl;
        throw std::exception("Failed to load font file");
    }
    int threadNumber= std::thread::hardware_concurrency();
    if(threadNumber==0)
    {
        threadNumber=1;
    }

    libraryWrapper = new LibraryWrapper(threadNumber);

    GroupRadioButton *groupRadioButton = new GroupRadioButton(200, 70, 50, 50, 10, texts, font,0);
    groupRadioButton->AddObserver(libraryWrapper);
    views.push_back(groupRadioButton);

    GroupRadioButton *functionsGroupRadioButton=new GroupRadioButton(220,70,300,50,20,functionNames,font,13,false);
    functionsGroupRadioButton->AddObserver(libraryWrapper);
    views.push_back(functionsGroupRadioButton);

    Button *buttonStart = new Button(200, 70, 50,230, "Start", font, Status::START);
    buttonStart->AddObserver(libraryWrapper);
    views.push_back(buttonStart);

    ImageLoader imageLoader;
    images.push_back(imageLoader.GetImageFromFile("Image1.bmp"));
    images.push_back(imageLoader.GetImageFromFile("Image2.bmp"));
    images.push_back(imageLoader.GetImageFromFile("Image3.bmp"));

    ImageButton *imageButton1 = new ImageButton(512, 288, 50, 350);
    imageButton1->AddImage(images[0]);
    imageButton1->AddImage(images[1]);
    imageButton1->AddImage(images[2]);
    views.push_back(imageButton1);

    libraryWrapper->SetImages(images);

    Button *buttonImage1 = new Button(200, 70, 300, 130, "Image 1", font, Status::CHANGETO1IMAGE);
    buttonImage1->AddObserver(imageButton1);
    buttonImage1->AddObserver(libraryWrapper);
    views.push_back(buttonImage1);

    Button *buttonImage2 = new Button(200, 70, 550, 130, "Image 2", font, Status::CHANGETO2IMAGE);
    buttonImage2->AddObserver(imageButton1);
    buttonImage2->AddObserver(libraryWrapper);
    views.push_back(buttonImage2);

    Button *buttonImage3 = new Button(200, 70, 800, 130, "Image 3", font, Status::CHANGETO3IMAGE);
    buttonImage3->AddObserver(imageButton1);
    buttonImage3->AddObserver(libraryWrapper);
    views.push_back(buttonImage3);

    ResultImage* resultImage=new ResultImage(512,288,600,350);
    libraryWrapper->ImageObservable::AddObserver(resultImage);
    views.push_back(resultImage);

    ShowTime* showTime=new ShowTime(200,70,600,250,"0 us",font);
    views.push_back(showTime);
    libraryWrapper->TimeObservable::AddObserver(showTime);

    Slider* slider=new Slider(220,300,250,font,threadNumber);
    slider->AddObserver(libraryWrapper);
    views.push_back(slider);
}


void Application::Run()
{
    while (mainWindow.isOpen())
    {
        HandleEvents();
        Draw();
    }
}

void Application::HandleEvents()
{
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mainWindow.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            for (auto x: views)
            {
                x->CheckEvent(event);
            }
        }
    }
}

void Application::Draw()
{
    if (mainWindow.isOpen())
    {
        mainWindow.clear(sf::Color(0, 0, 0, 0));

        for (auto x: views)
        {
            x->Draw(mainWindow);
        }

        mainWindow.display();
    }
}