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

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error occured during loading the font" << std::endl;
        throw std::exception("Failed to load font file");
    }
    libraryWrapper = new LibraryWrapper();

    GroupRadioButton *groupRadioButton = new GroupRadioButton(200, 70, 50, 50, 10, texts, font);
    groupRadioButton->AddObserver(libraryWrapper);
    views.push_back(groupRadioButton);

    Button *buttonStart = new Button(200, 70, 300, 50, "Start", font, Status::START);
    buttonStart->AddObserver(libraryWrapper);
    views.push_back(buttonStart);

    ImageLoader imageLoader;
    images.push_back(imageLoader.GetImageFromFile("Image1.bmp"));
    images.push_back(imageLoader.GetImageFromFile("Image2.bmp"));
    images.push_back(imageLoader.GetImageFromFile("Image3.bmp"));

    ImageButton *imageButton1 = new ImageButton(512, 288, 50, 250);
    imageButton1->AddImage(images[0]);
    imageButton1->AddImage(images[1]);
    imageButton1->AddImage(images[2]);
    imageButton1->SetImage(0);
    imageButton1->SetScale();
    views.push_back(imageButton1);

    libraryWrapper->SetImages(images);

    Button *buttonImage1 = new Button(200, 70, 550, 50, "Image 1", font, Status::CHANGETO1IMAGE);
    buttonImage1->AddObserver(imageButton1);
    buttonImage1->AddObserver(libraryWrapper);
    views.push_back(buttonImage1);

    Button *buttonImage2 = new Button(200, 70, 800, 50, "Image 2", font, Status::CHANGETO2IMAGE);
    buttonImage2->AddObserver(imageButton1);
    buttonImage2->AddObserver(libraryWrapper);
    views.push_back(buttonImage2);

    Button *buttonImage3 = new Button(200, 70, 1050, 50, "Image 3", font, Status::CHANGETO3IMAGE);
    buttonImage3->AddObserver(imageButton1);
    buttonImage3->AddObserver(libraryWrapper);
    views.push_back(buttonImage3);

    ResultImage* resultImage=new ResultImage(512,288,600,250);
    resultImage->SetImage(images[0]);
    resultImage->SetScale();
    libraryWrapper->ImageObservable::AddObserver(resultImage);
    views.push_back(resultImage);

    ShowTime* showTime=new ShowTime(200,70,550,150,"0 us",font);
    views.push_back(showTime);
    libraryWrapper->TimeObservable::AddObserver(showTime);
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