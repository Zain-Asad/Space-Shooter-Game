#include "game.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Menu
{
public:
    Texture tBadge;
    Sprite badges;

    Texture dismen;
    Texture disin;
    Texture disover;
    Texture dispause;
    Sprite disMen;
    Sprite disIn;
    Sprite disOver;
    Sprite disPause;

    Font font;
    int state; // 0 - Main Menu, 1 - Game, 2 - Instructions, 3 - Scores, 4 - Game Over, 5 - Pause
    string hscorenames[10] = {};
    int hscores[10] = {}; // accesses scores.txt and then stores the values
    fstream highScores;
    Menu()
    {
        tBadge.loadFromFile("img/badges.png");
        badges.setTexture(tBadge);
        dismen.loadFromFile("img/mainmenu.png");
        disMen.setTexture(dismen);
        disin.loadFromFile("img/instructions.png");
        disIn.setTexture(disin);
        disover.loadFromFile("img/over.png");
        disOver.setTexture(disover);
        dispause.loadFromFile("img/pause.png");
        disPause.setTexture(dispause);
        state = 0; // Set the initial menu state to the Main Menu
        font.loadFromFile("img/OpenSans-Semibold.ttf");
        highScores.open("scores.txt", ios::in);
        for (int i = 0; i < 10; i++)
        {

            highScores >> hscorenames[i];
            highScores >> hscores[i];
        }
        highScores.close();
    }
    void display_menu()
    {
        RenderWindow window(VideoMode(720, 1000), title);
        window.setFramerateLimit(165);
        Game *g = new Game;
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    g->bgm.~Music();
                    window.close();
                }
                else if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Escape)
                        state = 0;
                }
            }
            window.clear(Color::Black);
            window.draw(g->background);
            switch (state)
            {
            case 0: // Main Menu
                if (g->paused)
                    g->gameOver = true;
                display_main_menu(window);
                break;

            case 1: // Game
                if (g->gameOver)
                {
                    delete g;
                    g = new Game;
                }
                else if (g->paused)
                {
                    g->paused = false;
                }
                g->start_game(window);
                if (g->gameOver)
                {
                    store_scores(window, g);
                    state = 4;
                }
                else if (g->paused)
                    state = 5;
                break;

            case 2: // Instructions
                display_instructions(window);
                break;

            case 3: // Scores
                display_scores(window, g);
                break;

            case 4: // Game Over
                display_game_over(window, g);
                break;

            case 5: // Pause
                display_pause(window);
                break;
            }

            window.display();
        }
    }
    void display_main_menu(RenderWindow &window)
    {
        window.draw(disMen);
        if (Keyboard::isKeyPressed(Keyboard::Num1))
            state = 1; // Start the game

        if (Keyboard::isKeyPressed(Keyboard::Num2))
            state = 2; // Go to the Instructions screen

        if (Keyboard::isKeyPressed(Keyboard::Num3))
            state = 3; // Go to the Scores screen

        if (Keyboard::isKeyPressed(Keyboard::Num4))
            window.close(); // QUIT
    }
    void display_instructions(RenderWindow &window)
    {
        window.draw(disIn);
    }
    void display_game_over(RenderWindow &window, Game *g)
    {
        window.draw(disOver);
        if (Keyboard::isKeyPressed(Keyboard::Num1))
            state = 1; // Retry the game

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            state = 0; // Go back to the Main Menu
    }
    void display_pause(RenderWindow &window)
    {
        window.draw(disPause);

        if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            state = 1; // Resume the game
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            state = 0; // Go back to the Main Menu
        }
    }
    void store_scores(RenderWindow &window, Game *&g)
    {
        string playerName;
        Text userIn("", font, 30);
        userIn.setFillColor(Color::Black);
        userIn.setPosition(500, 350);
        bool typing = true;

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    g->bgm.~Music();
                    window.close();
                }
                else if (e.type == Event::TextEntered && typing)
                {
                    if (e.text.unicode >= 32 && e.text.unicode <= 126)
                    {
                        playerName += static_cast<char>(e.text.unicode);
                        userIn.setString(playerName);
                    }
                    else if (e.text.unicode == 8 && !playerName.empty())
                    {
                        playerName.pop_back();
                        userIn.setString(playerName);
                    }
                }
                else if (e.type == Event::KeyPressed && typing)
                {
                    if (e.key.code == Keyboard::Enter && !playerName.empty())
                    {
                        typing = false;
                        string tempname;
                        int tempscore;
                        if (g->score >= hscores[9])
                        {
                            highScores.open("scores.txt", ios::out);
                            hscorenames[9] = playerName;
                            hscores[9] = g->score;
                        }
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = i; j < 10; j++)
                            {
                                if (hscores[i] < hscores[j])
                                {
                                    tempname = hscorenames[i];
                                    tempscore = hscores[i];
                                    hscorenames[i] = hscorenames[j];
                                    hscores[i] = hscores[j];
                                    hscorenames[j] = tempname;
                                    hscores[j] = tempscore;
                                }
                            }
                        }
                        for (int i = 0; i < 10; i++)
                        {
                            highScores << hscorenames[i] + " " + to_string(hscores[i]);
                        }
                        highScores.close();
                        return;
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(g->background);

            Text prompt("Enter your name: ", font, 30);
            prompt.setFillColor(Color::Black);
            prompt.setPosition(200, 350);
            window.draw(prompt);
            window.draw(userIn);

            window.display();
        }
    }
    void display_scores(RenderWindow &window, Game *&g)
    {
        while (window.isOpen()){
            window.clear(Color::Black);
            window.draw(g->background);
            Text scoreTitle, showscores;
            scoreTitle.setFont(font);
            scoreTitle.setString("HIGH SCORES");
            scoreTitle.setCharacterSize(42);
            scoreTitle.setFillColor(Color(227, 133, 63, 255));
            scoreTitle.setStyle(Text::Bold);
            scoreTitle.setPosition(230, 50);
            window.draw(scoreTitle);
            showscores.setFont(font);
            showscores.setString("1. " + hscorenames[0] + ": " + to_string(hscores[0]) + "\n2. " + hscorenames[1] + ": " + to_string(hscores[1]) + "\n3. " + hscorenames[2] + ": " + to_string(hscores[2]) + "\n4. " + hscorenames[3] + ": " + to_string(hscores[3]) + "\n5. " + hscorenames[4] + ": " + to_string(hscores[4]) + "\n6. " + hscorenames[5] + ": " + to_string(hscores[5]) + "\n7. " + hscorenames[6] + ": " + to_string(hscores[6]) + "\n8. " + hscorenames[7] + ": " + to_string(hscores[7]) + "\n9. " + hscorenames[8] + ": " + to_string(hscores[8]) + "\n10. " + hscorenames[9] + ": " + to_string(hscores[9]));
            showscores.setCharacterSize(24);
            showscores.setFillColor(Color(255, 178, 108, 255));
            showscores.setStyle(Text::Bold);
            showscores.setPosition(30, 195);
            window.draw(showscores);
            Event m;
            while (window.pollEvent(m))
            {
                if (m.type == Event::Closed)
                {
                    g->bgm.~Music();
                    window.close();
                }
                if (m.type == Event::KeyPressed)
                {
                    if (m.key.code == Keyboard::Escape)
                    {
                        state = 0;
                        return;
                    }
                }
            }
            window.draw(badges);
            window.display();
        }
    }
};
