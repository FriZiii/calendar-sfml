#include <SFML/Graphics.hpp>

#include "SidePanel.h"
#include "Background.h"
#include "DaysOfTheWeek.h"
#include "DaysBoxes.h"
#include "Button.h"
#include "Logo.h"
#include "MonthAndYear.h"
#include "Functions.h"
#include "RightBarText.h"
#include "ColorPalettes.h"
#include "Text.h"
#include "ScrollButton.h"
#include "CreateYourOwnColorButton.h"
#include "TextInputDrawing.h"
#include "InputOutputManager.h"

#include <vector>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <string>

#pragma warning(disable : 4996)
int main()
{
    //Antialiasing
    sf::ContextSettings contextsettings;
    contextsettings.antialiasingLevel = 8;

    //Window
    sf::RenderWindow window(sf::VideoMode(1200, 610), "Calendar", 4U, contextsettings);

    //Icon of window
    sf::Image windowIcon;
    windowIcon.loadFromFile("Assets/Icon/Icon_256x256.png");
    window.setIcon(256, 256, windowIcon.getPixelsPtr());

    //Startup value
    bool home = true;
    bool credits = false;
    bool settings = false;

    bool show_Event = false;
    bool subbmit_Event = false;

    int marks = 0;
    int max_marks = 0;
    bool isClicked = false;

    std::string inputText{};

    std::fstream file;
    file.open("Startup/settings.txt", std::ios::in);
    int R{};
    int G{};
    int B{};

    if (file.good() == true)
    {
        file >> R;
        file >> G;
        file >> B;
    }
    file.close();
    sf::Color maincolor(R, G, B); //Purple

    //Font
    sf::Font font; font.loadFromFile("Fonts/WILD_WORLD.otf");
    sf::Font Roboto_Mono; Roboto_Mono.loadFromFile("Fonts/RobotoMono-Regular.ttf");
    //Background
    Background background;

    //Left and Right bar
    SidePanel left(sf::Vector2f(266.0f, 610.0f), sf::Vector2f(0.0f, 0.0f), maincolor);
    SidePanel right(sf::Vector2f(286.0f, 87.0f), sf::Vector2f(914.0f, 0.0f), maincolor);

    //Logo
    Logo logo(sf::Vector2f(133.0f, 45.0f), sf::Vector2f(105,105), "Assets/Logo.png");

    //Buttons left bar
    std::vector<Button>button;
    button.push_back(Button(sf::Vector2f(20.0f, 190.0f), font, "HOME", false, maincolor));
    button.push_back(Button(sf::Vector2f(20.0f, 290.0f), font, "SETTINGS",false, maincolor));
    button.push_back(Button(sf::Vector2f(20.0f, 390.0f), font, "CREDITS", false, maincolor));
    button.push_back(Button(sf::Vector2f(20.0f, 490.0f), font, "EXIT", false, maincolor));

    //Month and Year
        //Getting actual month and year
        time_t theTime = time(NULL);
        struct tm* aTime = localtime(&theTime);
        int actualmonth = aTime->tm_mon + 1;
        int actualyear = aTime->tm_year + 1900;
        int actualday = aTime->tm_yday;

    MonthAndYear monthAndYear(actualmonth, actualyear, font, maincolor);

    //Days of the week
    std::vector<DaysOfTheWeek>daysoftheweek;

    for (int i = 0; i <= 6; i++)
    {
        sf::Vector2f position(293.0f + (float)i * (68.0f + 20.0f), 121.0f);
        daysoftheweek.push_back(DaysOfTheWeek(i, position, font));
    }

    //Boxes of the day
    std::vector<DaysBoxes>daysboxes;

    int daysCount = 0;
    int weekDay = zellerArgorithm(monthAndYear.GetMonth(), monthAndYear.GetYear()); //How many days we have to skip
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            if (daysCount < DaysCount(monthAndYear.GetMonth(), monthAndYear.GetYear()))//If the current day is less than the number of days in the month, we increase the next day
            {
                daysCount++;
            }
            else
            {
                daysCount = 50;//otherwise, we set a placeholder
            }

            sf::Vector2f position(293.0f + (float)j * (68.0f + 20.0f), 151.0f + (float)i * 72.0f);
            daysboxes.push_back(DaysBoxes(position, font, daysCount, weekDay));
            weekDay--;
        }
    }

    //Right bar text;
    int day{};
    RightBarText rightbartext(font);

    //Settings 
    //ColorPallets
    Text colorpalettesText("PICK YOUR ", sf::Vector2f(455.0f, 75.0f), font, "COLOR", maincolor, 40);
    Text scrollbuttonText("or create your own", sf::Vector2f(470.0f, 230.0f), font, 40);

    std::vector<ColorPalettes> colorpalettes;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        sf::Vector2f position(344.0f + 30.0f + ((float)i * 80.0f), 175.0f);
        colorpalettes.push_back(ColorPalettes(position, k));
        k++;
    }
    //ScrollButtons
    ScrollButton scrollR(sf::Vector2f(344.0f, 320));
    ScrollButton scrollG(sf::Vector2f(344.0f, 370));
    ScrollButton scrollB(sf::Vector2f(344.0f, 420));

    CreateYourOwnColorButton buttoncolor(sf::Vector2f(1000, 380));

    //Credits
        Logo credits_bg(sf::Vector2f(745.0f, 10.0f), sf::Vector2f(927, 501), "Assets/Credits.png");

    //Event 
    TextInputDrawing textinputDrawing(Roboto_Mono, inputText);

    Button addevent(sf::Vector2f(945.0f, 500.0f), font, "ADD EVENT", true, maincolor);
    Button submit(sf::Vector2f(945.0f, 500.0f), font, "SUBMIT", true, maincolor);
    Button delete_event(sf::Vector2f(945.0f, 500.0f), font, "DELETE", true, maincolor);

    SidePanel eventBackground(sf::Vector2f(286.0f, 367.0f), sf::Vector2f(914.0f, 130.0f), sf::Color(232, 232, 232));
    InputOutputManager output_manager;
    InputOutputManager input_manager;
    InputOutputManager remove_manager;

    //Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::ofstream ofs;
                ofs.open("Startup/settings.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();

                file.open("Startup/settings.txt", std::ios::out);

                if (file.good() == true)
                {
                    file << R << ' ' << G << ' ' << B << ' ';
                }
                window.close();
            }
            else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isClicked = true;
            }
            else
            {
                isClicked = false;
            }
            
            //Text input
            if (subbmit_Event && max_marks <= 208)
            {
                if (event.type == sf::Event::TextEntered)
                {
                    if (std::isprint(event.text.unicode))
                    {
                        inputText += event.text.unicode;
                        marks++;
                        max_marks++;
                    }
                }
                else if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::BackSpace)
                    {
                        if (!inputText.empty())
                        {
                            inputText.pop_back();
                            marks--;
                            max_marks--;
                        }
                    }
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        inputText += '\n';
                        marks = 0;
                    }
                }
            }
        }

        //Updates
        for (Button& button : button)
            button.Update(window, maincolor);

        left.Update(maincolor);

        if (button[0].IsHover(window) && isClicked)
        {
            home = true;
            settings = false;
            credits = false;
        }
        else if (button[1].IsHover(window) && isClicked)
        {
            home = false;
            settings = true;
            credits = false;
        }
        else if (button[2].IsHover(window) && isClicked)
        {
            home = false;
            settings = false;
            credits = true;
        }
        else if (button[3].IsHover(window) && isClicked)
        {
            std::ofstream ofs;
            ofs.open("Startup/settings.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();

            file.open("Startup/settings.txt", std::ios::out);
            if (file.good() == true)
            {
                file << R << ' ' << G << ' ' << B << ' ';
            }
            window.close();
        }

        // After clicking remove event
        if (delete_event.IsHover(window) && isClicked && show_Event)
        {
            std::string fileNameString = remove_manager.GetFileName(monthAndYear.GetYear(), monthAndYear.GetMonth(), day);
            int lengthofFileName = fileNameString.length();
            char *fileName = new char[lengthofFileName+1];
            //Convert string to char
            strcpy(fileName, fileNameString.c_str());

            remove(fileName);
        }
        // After clicking stop showing the add event button and stat showing submit button
        else if (addevent.IsHover(window) && isClicked && !subbmit_Event)
        {
            subbmit_Event = true;
        }
        //After clicking save the text to file, delete_event the text and stop showing the submit button
        else if (submit.IsHover(window) && isClicked && subbmit_Event)
        {
            if(inputText !="")
                input_manager.SaveEventToFile(monthAndYear.GetYear(), monthAndYear.GetMonth(), day, inputText);

            inputText = "";
            subbmit_Event = false;
        }

        if (home && !credits && !settings)
        {
            right.Update(maincolor);
            monthAndYear.HoverEffect(window, maincolor);
            if (isClicked)
            {
                monthAndYear.Update(window,maincolor);
                isClicked = false;
            }

            int daysCount = 0;
            int weekDay = zellerArgorithm(monthAndYear.GetMonth(), monthAndYear.GetYear());//How many days we have to skip
            for (DaysBoxes& daysboxes : daysboxes)
            {
                if (weekDay <= 0)
                {
                    if (daysCount < DaysCount(monthAndYear.GetMonth(), monthAndYear.GetYear()))//If the current day is less than the number of days in the month, we increase the next day
                        daysCount++;
                    else
                        daysCount = 50;//otherwise, we set a placeholder
                }
                daysboxes.Update(window, daysCount, weekDay, maincolor, R, G, B);
                weekDay--;

                if (daysboxes.isClick(window))
                {
                    day = daysboxes.GetDay(window);
                }
            }

            InputOutputManager input_output_manager;
            if (input_output_manager.foundFile(monthAndYear.GetYear(), monthAndYear.GetMonth(), day))
            {
                show_Event = true;
            }
            else
            {
                show_Event = false;
            }

            rightbartext.Update(day, monthAndYear.GetMonthString(), right.GetSize(), right.GetPosition());

            if (!show_Event && !subbmit_Event)
            {
                addevent.Update(window, maincolor);
            }

            if (subbmit_Event)
            {
                submit.Update(window, maincolor);
                textinputDrawing.Update(inputText);
                if (marks >= 19)
                {
                    inputText += '\n';
                    marks = 0;
                }
                if (inputText == "")
                {
                    marks = 0;
                }
            }

            if (show_Event)
            {
                delete_event.Update(window, maincolor);
            }
        }
        if (!home && !credits && settings)
        {
            if (scrollR.GetIterator() == 255 && scrollG.GetIterator() == 255 && scrollB.GetIterator() == 255)
            {
                std::cout << "Nie polecamy takiego koloru" << std::endl;
            }

            for (ColorPalettes & colorpalettes : colorpalettes)
            {
                colorpalettes.Update(window);

                if (isClicked && colorpalettes.isHover(window))
                {
                    R = colorpalettes.getColorR(window);
                    G = colorpalettes.getColorG(window);
                    B = colorpalettes.getColorB(window);
                }
            }

            scrollR.Update(window, "R");
            scrollG.Update(window, "G");
            scrollB.Update(window, "B");

           if (buttoncolor.isHover(window) && isClicked)
           {
               R = scrollR.GetIterator();
               G = scrollG.GetIterator();
               B = scrollB.GetIterator();
           }

           maincolor = sf::Color(R, G, B);
           sf::Color ownColor = sf::Color(scrollR.GetIterator(), scrollG.GetIterator(), scrollB.GetIterator());
           buttoncolor.Update(window, ownColor);
           colorpalettesText.Update(maincolor);
        }

        //Draw
        window.clear(sf::Color::White);

        left.Draw(window);
        logo.Draw(window);

        for (Button& button : button)
            button.Draw(window);

        if (home && !credits && !settings)
        {
            background.Draw(window);

            right.Draw(window);

            for (DaysOfTheWeek& daysoftheweek : daysoftheweek)
                daysoftheweek.Draw(window);

            for (DaysBoxes& daysboxes : daysboxes)
                daysboxes.Draw(window);

            monthAndYear.Draw(window);

            rightbartext.Draw(window);

            //Show the event that you found in the file
            if (show_Event)
            {
                eventBackground.Draw(window);
                delete_event.Draw(window);
                output_manager.DrawTextFromFile(monthAndYear.GetYear(), monthAndYear.GetMonth(), day, Roboto_Mono, window, maincolor);
            }
            // If you have not found the event file, show the option of adding an event
            else if (!show_Event && !subbmit_Event)
            {
                addevent.Draw(window);
            }
            //If you have entered an event, save it to a file
            else if (subbmit_Event)
            {
                eventBackground.Draw(window);
                submit.Draw(window);
                textinputDrawing.Draw(window);
            }

        }
        if (!home && !credits && settings)
        {
            colorpalettesText.Draw(window);

            for (ColorPalettes& colorpalettes : colorpalettes)
                colorpalettes.Draw(window);

            scrollbuttonText.Draw(window);

            scrollR.Draw(window);
            scrollG.Draw(window);
            scrollB.Draw(window);
            buttoncolor.Draw(window);
        }
        if (!home && credits && !settings)
        {
            credits_bg.Draw(window);
        }

        window.display();
    }

    return 0;
}