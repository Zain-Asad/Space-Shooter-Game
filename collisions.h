#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "game.h"

using namespace std;
using namespace sf;

bool collision(Sprite s1, Sprite s2)
{

    bool answer = false;
    Rect<float> r1 = s1.getGlobalBounds(), r2 = s2.getGlobalBounds();
    float left = max(r1.left, r2.left);
    float top = max(r1.top, r2.top);
    float right = min(r1.left + r1.width, r2.left + r2.width);
    float bottom = min(r1.top + r1.height, r2.top + r2.height); // checks for the largest and smallest of each pair of coordinates

    if (left < right && top < bottom) // if overlap occurs, these values will show inconsistency
    {
        answer = true;
    }

    return answer;
}

void check_collisions(Player *&p, Enemy *&boss, bool isDragon, bool isMonster)
{
    if (collision(p->sprite, boss->esprite))
    {
        if (!p->power && p->lives > 0)
            p->lives--;
    }
    if (p->shoot != nullptr)
    {
        if (p->shoot != nullptr)
        {
            if (p->power == false)
            {
                if (collision(p->shoot->bulsprite, boss->esprite))
                {
                    boss->health--;
                    if (boss->health == 0)
                        boss->timetoStay = 0;
                    if (!p->isFire)
                    {
                        delete p->shoot;
                        p->shoot = nullptr;
                        p->canFire = true;
                    }
                }
            }
            else if (p->power)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (p->shoot[j].exists)
                    {
                        if (collision(p->shoot[j].bulsprite, boss->esprite))
                        {
                            boss->health--;
                            if (boss->health == 0)
                            {
                                boss->timetoStay = 0;
                            }
                            if (p->isFire == false)
                            {
                                p->shoot[j].exists = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (boss->attack != nullptr)
    {
        if (isDragon)
        {
            for (int i = 0; i < 7; i++)
            {
                if (collision(p->sprite, boss->attack[i].bsprite))
                {
                    if (boss->attack[i].exists)
                    {
                        if (!p->power && p->lives > 0)
                            p->lives--;
                        boss->attack[i].exists = false;
                    }
                }
            }
        }
        else if (isMonster)
        {
            for (int i = 0; i < 3; i++)
            {
                if (collision(p->sprite, boss->attack[i].bsprite))
                {
                    if (boss->attack[i].exists)
                    {
                        if (!p->power && p->lives > 0)
                            p->lives--;
                        boss->attack[i].exists = false;
                    }
                }
            }
        }
    }
}

void check_collisions(Player *&p, Enemy *enemy[10], int &score, int &level)
{
    for (int i = 0; i < 12; i++)
    {
        if (enemy[i]->exists)
        {
            if (collision(p->sprite, enemy[i]->esprite))
            {
                if (!p->power && p->lives > 0)
                    p->lives--;
                enemy[i]->health--;
                if (enemy[i]->health == 0)
                    enemy[i]->exists = false;
            }
            if (enemy[i]->attack != nullptr)
            {
                if (collision(p->sprite, enemy[i]->attack->bsprite))
                {
                    if (!p->power && p->lives > 0)
                        p->lives--;
                    enemy[i]->attack->exists = 0;
                    delete enemy[i]->attack;
                    enemy[i]->attack = nullptr;
                }
            }
            if (p->shoot != nullptr)
            {
                if (p->power == false)
                {
                    if (collision(p->shoot->bulsprite, enemy[i]->esprite))
                    {
                        enemy[i]->health--;
                        if (enemy[i]->health == 0)
                        {
                            if (enemy[i]->type == 1)
                            {
                                score += 10 * level;
                            }
                            else if (enemy[i]->type == 2)
                            {
                                score += 20 * level;
                            }
                            else if (enemy[i]->type == 3)
                            {
                                score += 30 * level;
                            }
                            enemy[i]->exists = false;
                            delete enemy[i]->attack;
                            enemy[i]->attack = nullptr;
                        }
                        if (!p->isFire)
                        {
                            delete p->shoot;
                            p->shoot = nullptr;
                            p->canFire = true;
                        }
                    }
                }
                else if (p->power)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        if (p->shoot[j].exists)
                        {
                            if (collision(p->shoot[j].bulsprite, enemy[i]->esprite))
                            {
                                enemy[i]->health--;
                                if (enemy[i]->health == 0)
                                {
                                    enemy[i]->exists = false;
                                    delete enemy[i]->attack;
                                    enemy[i]->attack = nullptr;
                                }
                                if (!p->isFire)
                                {
                                    p->shoot[j].exists = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}