#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
#include "collisions.h"
#include "spawns.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Texture bg_live;
    Sprite live;

    Player *p; // player
    Music bgm;

    Text tLevel;
    Text tScore;
    Font gFont;

    int level;
    bool playanimation;

    int score;
    bool gameOver;
    bool paused;

    bool isDragon;
    bool isMonster;
    bool bossSpawned;

    bool waveSpawned;

    bool addspawn;

    Enemy *wave[12];
    Enemy *boss;
    AddOns *add;

    Game()
    {
        gFont.loadFromFile("img/OpenSans-Semibold.ttf");

        tLevel.setFont(gFont);
        tLevel.setFillColor(Color::Red);
        tScore.setFont(gFont);
        tScore.setFillColor(Color::Red);

        bg_live.loadFromFile("img/live.png");
        live.setTexture(bg_live);

        bgm.openFromFile("img/Skyrim 8-Bit Theme.ogg");
        bgm.setVolume(75);
        bgm.setPlayingOffset(seconds(0.0f));
        bgm.setLoop(true);
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
        level = 1;
        score = 0;
        isDragon = false;
        isMonster = false;
        waveSpawned = false;
        bossSpawned = false;
        boss = nullptr;
        add = nullptr;
        addspawn = false;
        gameOver = false;
        paused = false;
        playanimation = false;
    }
    void start_game(RenderWindow &window)
    {
        srand(time(0));
        bgm.setVolume(75);
        bgm.play();
        Clock clock;
        float timer = 0;
        float bosstime = 0;
        float bosslife = 0;
        float droptime = 0;
        float addspawntime = 0;
        float powertime = 0;
        float firetime = 0;
        while (window.isOpen())
        {
            window.clear(Color::Black);
            window.draw(background);
            window.draw(live);
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                {
                    bgm.~Music();
                    window.close();
                } // close the game
            }
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            bosstime += time;
            droptime += time;
            if (p->isFire)
            {
                firetime += time;
                if (firetime >= 5 && p->shoot == nullptr)
                {
                    p->isFire = false;
                    firetime = 0;
                }
            }
            if (p->power)
            {
                powertime += time;
                if (powertime >= 3 && p->shoot == nullptr)
                {
                    p->power = false;
                    powertime = 0;
                }
            }

            if (add != nullptr)
                addspawntime += time;
            else
                addspawntime = 0;

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                p->move("l");
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                p->move("r");
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                p->move("u");
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                p->move("d");
            }
            if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
            {
                p->tex.loadFromFile("img/player_ship_UR.png");
                p->sprite.setTexture(p->tex);
                p->sprite.setScale(1.35, 1.35);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
            {
                p->tex.loadFromFile("img/player_ship_UL.png");
                p->sprite.setTexture(p->tex);
                p->sprite.setScale(1.35, 1.35);
            }
            else
            {
                p->tex.loadFromFile("img/player_ship.png");
                p->sprite.setTexture(p->tex);
                p->sprite.setScale(1.1, 1.1);
            }
            if (bosstime >= 10.00)
            {
                if (isMonster == false && isDragon == false)
                {
                    if ((rand() % 5 + 1) == (rand() % 5 + 1))
                    {
                        isMonster = true;
                    }
                    else if ((rand() % 5 + 1) == (rand() % 5 + 1))
                    {
                        isDragon = true;
                    }
                }
                bosstime = 0;
            }
            if (bossSpawned == false)
            {
                if (waveSpawned == false)
                {
                    if (playanimation)
                    {
                        playanimation = false;
                    }
                    int shape;
                    if (level == 1)
                    {
                        shape = rand() % 3 + 1;
                    }
                    else if (level == 2)
                    {
                        shape = rand() % 3 + 4;
                    }
                    else if (level == 3)
                    {
                        shape = rand() % 6 + 1;
                    }
                    for (int i = 0; i < 12; i++)
                    {
                        int etype = rand() % 3 + 1;
                        switch (etype)
                        {
                        case 1:
                            wave[i] = new Alpha(0, 0, i);
                            break;
                        case 2:
                            wave[i] = new Beta(0, 0, i);
                            break;
                        case 3:
                            wave[i] = new Gamma(0, 0, i);
                            break;
                        }
                        switch (shape)
                        {
                        case 1:
                            rectangle(wave[i], i);
                            break;
                        case 2:
                            triangle(wave[i], i);
                            break;
                        case 3:
                            cross(wave[i], i);
                            break;
                        case 4:
                            heart(wave[i], i);
                            break;
                        case 5:
                            diamond(wave[i], i);
                            break;
                        case 6:
                            circle(wave[i], i);
                            break;
                        }
                    }
                    waveSpawned = true;
                }

                else if (waveSpawned == true)
                {
                    bool wavelife = false;
                    for (int i = 0; i < 12; i++)
                    {
                        if (wave[i]->exists)
                        {
                            wavelife = true;
                            window.draw(wave[i]->esprite);
                            wave[i]->behaviour(time);
                            if (wave[i]->attack != nullptr)
                            {
                                window.draw(wave[i]->attack->bsprite);
                            }
                        }
                    }
                    if (wavelife == false)
                    {
                        waveSpawned = false;
                    }
                }
            }
            if (bossSpawned == false)
            {
                if (isDragon)
                {
                    boss = new Dragon;
                    bossSpawned = true;
                }
                else if (isMonster)
                {
                    boss = new Monster;
                    bossSpawned = true;
                }
            }
            else if (bossSpawned == true)
            {
                if (boss != nullptr)
                {
                    if (boss->exists)
                    {
                        if (bosslife < boss->timetoStay)
                        {
                            boss->behaviour(time);
                            bosslife += time;
                            window.draw(boss->esprite);
                            if (boss->attack != nullptr && isMonster)
                            {
                                for (int i = 0; i < 3; i++)
                                    if (boss->attack[i].exists)
                                        window.draw(boss->attack[i].bsprite);
                            }
                            else if (boss->attack != nullptr && isDragon)
                            {
                                for (int i = 0; i < 7; i++)
                                    if (boss->attack[i].exists)
                                        window.draw(boss->attack[i].bsprite);
                            }
                        }
                        if (bosslife >= boss->timetoStay)
                        {
                            if (isDragon)
                            {
                                score += level * 125;
                            }
                            else if (isMonster)
                            {
                                score += level * 75;
                            }
                            boss->exists = false;
                            isDragon = false;
                            isMonster = false;
                            bossSpawned = false;
                            bosslife = 0;
                            delete boss;
                            boss = nullptr;
                        }
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                p->fire();
            }
            p->playerbullet();
            if (p->shoot != nullptr)
            {
                if (p->power == false)
                {
                    if (p->shoot->exists == true)
                        window.draw(p->shoot->bulsprite);
                }
                else if (p->power == true)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        if (p->shoot[i].exists)
                        {
                            window.draw(p->shoot[i].bulsprite);
                        }
                    }
                }
            }
            window.draw(p->sprite);

            if (addspawn == false)
            {
                if (droptime >= 5)
                {
                    droptime = 0;
                    if (rand() % 2 + 1 == 1)
                    {
                        addspawn = true;
                        int spawntype = rand() % 4;
                        switch (spawntype)
                        {
                        case 0:
                            if (add != nullptr)
                                delete add;
                            add = new AddOns(spawntype, "img/PNG/Power-ups/powerupGreen_bolt.png", rand() % 600 + 75, 500, 1);
                            break;
                        case 1:
                            if (add != nullptr)
                                delete add;
                            add = new AddOns(spawntype, "img/PNG/Power-ups/powerupRed_bolt.png", rand() % 600 + 75, 500, 1);
                            break;
                        case 2:
                            if (add != nullptr)
                                delete add;
                            add = new AddOns(spawntype, "img/PNG/Power-ups/pill_red.png", rand() % 600 + 75, 500, 1);
                            break;
                        case 3:
                            if (add != nullptr)
                                delete add;
                            add = new AddOns(spawntype, "img/PNG/Meteors/meteorBrown_med1.png", rand() % 600 + 75, 500, 0.5);
                            break;
                        }
                    }
                }
            }
            else if (addspawn == true)
            {
                if (add != nullptr)
                {
                    if (add->y >= 900 && add->type == 3)
                    {
                        delete add;
                        add = nullptr;
                        addspawntime = 0;
                        addspawn = false;
                        score += 10 * level;
                    }
                    else if (collision(p->sprite, add->asprite))
                    {
                        if (add->type == 0)
                        {
                            powertime = 0;
                            if (p->shoot != nullptr)
                            {
                                if (p->power)
                                {
                                }
                                else
                                {
                                    p->power = true;
                                    delete p->shoot;
                                    p->shoot = nullptr;
                                    p->canFire = true;
                                }
                            }
                            else if (p->shoot == nullptr)
                            {
                                p->power = true;
                            }
                        }
                        else if (add->type == 1)
                        {
                            firetime = 0;
                            if (p->shoot != nullptr)
                            {
                                if (p->isFire)
                                {
                                }
                                else
                                {
                                    p->isFire = true;
                                    if (!p->power)
                                        delete p->shoot;
                                    else
                                        delete[] p->shoot;
                                    p->shoot = nullptr;
                                    p->canFire = true;
                                }
                            }
                            else if (p->shoot == nullptr)
                            {
                                p->isFire = true;
                            }
                        }
                        else if (add->type == 2)
                        {
                            if (p->lives < 3)
                            {
                                p->lives++;
                            }
                        }
                        else if (add->type == 3)
                        {
                            if (p->lives > 0 && !p->power)
                                p->lives--;
                        }
                        delete add;
                        add = nullptr;
                        addspawntime = 0;
                        addspawn = false;
                    }
                    else
                    {
                        add->move();
                        window.draw(add->asprite);
                    }
                }
                if (addspawntime >= 10)
                {
                    delete add;
                    add = nullptr;
                    addspawntime = 0;
                    addspawn = false;
                }
            }
            if (bossSpawned)
            {
                check_collisions(p, boss, isDragon, isMonster);
            }
            else if (!bossSpawned && wave != nullptr)
            {
                check_collisions(p, wave, score, level);
            }
            if (score >= 300)
            {
                playanimation = true;
                level = 3;
            }
            else if (score >= 50)
            {
                playanimation = true;
                level = 2;
            }
            p->dLives.setPosition(10, 950);
            for (int i = 1; i <= p->lives; i++)
            {
                window.draw(p->dLives);
                p->dLives.setPosition(10 + (i * 50), 950);
            }
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                paused = true;
                bgm.setVolume(30);
                return;
            }
            if (p->lives == 0)
            {
                gameOver = true;
                bgm.stop();
                return;
            }
            tScore.setString(to_string(score));
            tScore.setPosition(600, 965);
            tLevel.setString(to_string(level));
            tLevel.setPosition(285, 965);
            window.draw(tScore);
            window.draw(tLevel);
            window.display();
        }
    }
};
#endif
