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

#include <vector>
#include <time.h>
#include <fstream>

#pragma warning(disable : 4996)

int main()
{
    //Antialiasing
    sf::ContextSettings contextsettings;
    contextsettings.antialiasingLevel = 8;

    //Window
    sf::RenderWindow window(sf::VideoMode(1200, 610), "Calendar", 4U, contextsettings);

    //Startup value
    bool home = true;
    bool credits = false;
    bool settings = false;

    bool isClicked = false;

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

    //Background
    Background background;

    //Left and Right bar
    SidePanel left(sf::Vector2f(266.0f, 610.0f), sf::Vector2f(0.0f, 0.0f), maincolor);
    SidePanel right(sf::Vector2f(286.0f, 87.0f), sf::Vector2f(914.0f, 0.0f), maincolor);

    //Logo
    Logo logo(sf::Vector2f(133.0f, 45.0f), sf::Vector2f(105,105), "Assets/Logo.png");

    //Buttons left bar
    std::vector<Button>button;
    button.push_back(Button(sf::Vector2f(20.0f, 190.0f), font, "HOME"));
    button.push_back(Button(sf::Vector2f(20.0f, 290.0f), font, "SETTINGS"));
    button.push_back(Button(sf::Vector2f(20.0f, 390.0f), font, "CREDITS"));
    button.push_back(Button(sf::Vector2f(20.0f, 490.0f), font, "EXIT"));

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
            sf::Vector2f position(344.0f + 30.0f + ( (float)i * 80.0f), 175.0f);
            colorpalettes.push_back(ColorPalettes(position, k));
            k++;
        }
        //ScrollButtons
        ScrollButton scrollR(sf::Vector2f(344.0f, 320));
        ScrollButton scrollG(sf::Vector2f(344.0f, 370));
        ScrollButton scrollB(sf::Vector2f(344.0f, 420));

        CreateYourOwnColorButton buttoncolor(sf::Vector2f(1000, 380));

    //Credits
    Logo antarmy(sf::Vector2f(1080.0f, 5.0f), sf::Vector2f(1162/10,1276/10), "Assets/AntArmy.png");

    std::vector<Text> creditstext;
    creditstext.push_back(Text("ANT ARMY STUDIOS", sf::Vector2f(455, 50), font, 32));

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
        }

        //Updates
        for (Button& button : button)
            button.Update(window, maincolor);
        left.Update(maincolor);
        if (button[0].IsClicked(window))
        {
            home = true;
            settings = false;
            credits = false;
        }
        else if (button[1].IsClicked(window))
        {
            home = false;
            settings = true;
            credits = false;
        }
        else if (button[2].IsClicked(window))
        {
            home = false;
            settings = false;
            credits = true;
        }
        else if (button[3].IsClicked(window))
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

        if (home && !credits && !settings)
        {
            right.Update(maincolor);
            if (isClicked)
            {
                monthAndYear.Update(window,maincolor);
                isClicked = false;
            }
            monthAndYear.HoverEffect(window, maincolor);


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
                    day = daysboxes.GetDay(window);
            }

            rightbartext.Update(day, monthAndYear.GetMonthString(), right.GetSize(), right.GetPosition());
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
            antarmy.Draw(window);
            for (Text& creditstext : creditstext)
                creditstext.Draw(window);
        }

        window.display();
    }

    return 0;
}