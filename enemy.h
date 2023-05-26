#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
using namespace sf;
using namespace std;

class Bomb
{
public:
    float x;
    float y;
    float delx;
    float dely;
    float speed;
    bool exists;
    Texture b;
    Sprite bsprite;
    Bomb(string png_path, float x, float y, float delx, float dely)
    {
        b.loadFromFile(png_path);
        bsprite.setTexture(b);
        this->x = x;
        this->y = y;
        this->delx = delx;
        this->dely = dely;
        speed = 1.25;
        exists = true;
        bsprite.setPosition(x + 30, y);
        bsprite.setScale(0.5, 0.5);
    }
    Bomb(string png_path, float x, float y, float delx, float dely, int size, int speed)
    {
        b.loadFromFile(png_path);
        bsprite.setTexture(b);
        this->x = x;
        this->y = y;
        this->delx = delx;
        this->dely = dely;
        this->speed = speed;
        exists = true;
        bsprite.setPosition(x + 30, y);
        bsprite.setScale(size, size);
    }
    void move()
    {
        if (this->y <= 1080 && x <= 720 && x >= -720)
        {
            y += dely * speed;
            x += delx * speed;
            bsprite.move(delx * speed, dely * speed);
        }
        else
        {
            exists = false;
        }
    }
};

class Enemy
{ // Enemy Class, contains attributes for most enemies
public:
    float timetoStay;
    float x;
    float y;
    int health;
    Bomb *attack;
    bool exists;
    Texture e;
    Sprite esprite;

    int type;

    virtual void behaviour(float atime) = 0;
};

class Invader : public Enemy
{
public:
    float attackInterval;
    float delay;
    int index;
    Invader(float x, int i)
    {
        attackInterval = x;
        delay = x;
        index = i;
    }
    virtual void behaviour(float atime) = 0;
};

class Monster : public Enemy
{
    bool moving;
    bool moveleft;
    bool moveright;
    int attacksFired;

public:
    Monster()
    {
        health = 25;
        timetoStay = 15;
        attack = nullptr;
        x = 200;
        y = 10;
        e.loadFromFile("img/monster1.png");
        esprite.setTexture(e);
        esprite.setPosition(x, y);
        esprite.setScale(0.5, 0.5);
        this->exists = 1;
        moving = false;
        attacksFired = 0;
        type = 4;
        if (rand() % 2 + 1 == 1)
        {
            moveright = true;
            moveleft = false;
        }
        else
        {
            moveright = false;
            moveleft = true;
        }
    }
    void behaviour(float atime) override
    {
        if (moving == false)
        {
            if (this->attack == nullptr)
            {
                this->attack = new Bomb[3]{Bomb("img/PNG/Lasers/laserRed13.png", this->x + 105, this->y + 300, 0, 1, 1, 3), Bomb("img/PNG/Lasers/laserRed13.png", this->x + 135, this->y + 300, 0, 1, 1, 3), Bomb("img/PNG/Lasers/laserRed13.png", this->x + 165, this->y + 300, 0, 1, 1, 3)};
            }
            if (this->attack != nullptr)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (this->attack[i].exists)
                    {
                        this->attack[i].move();
                    }
                    else
                    {
                        this->attack[i].exists = false;
                    }
                }
                bool check = true;
                for (int i = 0; i < 3; i++)
                {
                    if (this->attack[i].exists != false)
                    {
                        check = false;
                    }
                }
                if (check == true)
                {
                    attacksFired++;
                    delete[] attack;
                    attack = nullptr;
                    if (attacksFired == 3)
                    {
                        moving = true;
                        attacksFired = 0;
                    }
                }
            }
        }
        else
        {
            monsterMove();
        }
    }
    void monsterMove()
    {
        if (x >= 0 && x <= 410 && moveright == true)
        {
            if (x == 410)
            {
                moving = false;
                moveright = false;
                moveleft = true;
            }
            else
            {
                x += 0.5;
                esprite.move(0.5, 0);
            }
        }
        else if (x <= 410 && x >= 0 && moveleft == true)
        {
            if (x == 0)
            {
                moving = false;
                moveright = true;
                moveleft = false;
            }
            else
            {
                x -= 0.5;
                esprite.move(-0.5, 0);
            }
        }
    }
};

class Dragon : public Enemy
{
public:
    Dragon()
    {
        health = 75;
        timetoStay = 5;
        attack = nullptr;
        x = 200;
        y = 10;
        e.loadFromFile("img/dragon.png");
        esprite.setTexture(e);
        esprite.setPosition(x, y);
        esprite.setScale(1.5, 1.5);
        this->exists = 1;
        type = 5;
    }
    void behaviour(float atime) override
    {
        if (this->attack == nullptr)
        {
            this->attack = new Bomb[7]{Bomb("img/fire.png", this->x + 25, this->y + 320, -1.25, 1, 2, 2), Bomb("img/fire.png", this->x + 40, this->y + 320, -0.85, 1, 2, 2), Bomb("img/fire.png", this->x + 70, this->y + 320, -0.5, 1, 2, 2.75), Bomb("img/fire.png", this->x + 100, this->y + 320, 0, 1, 2, 3), Bomb("img/fire.png", this->x + 130, this->y + 320, 0.5, 1, 2, 2.75), Bomb("img/fire.png", this->x + 160, this->y + 320, 0.85, 1, 2, 2.25), Bomb("img/fire.png", this->x + 175, this->y + 320, 1.25, 1, 2, 2.25)};
        }
        if (this->attack != nullptr)
        {
            for (int i = 0; i < 7; i++)
            {
                if (this->attack[i].exists)
                {
                    this->attack[i].move();
                }
            }
        }
        bool check = true;
        for (int i = 0; i < 7; i++)
        {
            if (this->attack[i].exists != false)
            {
                check = false;
            }
        }
        if (check == true)
        {
            delete[] attack;
            attack = nullptr;
        }
    }
};

class Alpha : public Invader
{
public:
    Alpha(float x = 200, float y = 200, int i = 0) : Invader(5.0, i)
    {
        timetoStay = 100;
        this->x = x;
        this->y = y;
        e.loadFromFile("img/enemy_1.png");
        esprite.setTexture(e);
        esprite.setPosition(x, y);
        esprite.setScale(0.61, 0.625);
        this->exists = 1;
        this->attack = nullptr;
        health = 1;
        type = 1;
    }
    void behaviour(float atime) override
    {
        srand(time(0));
        if (this->attack != nullptr)
        {
            if (this->attack->exists == true)
            {
                this->attack->move();
            }
            else if (this->attack->exists == false)
            {
                delete this->attack;
                this->attack = nullptr;
            }
        }
        int randNum = rand() % (4 + this->index) + 1;
        if (this->attack == nullptr && this->delay >= attackInterval && randNum == 1)
        {
            this->attack = new Bomb("img/PNG/Lasers/laserBlue01.png", this->x, this->y, 0, 1);
            this->delay = 0;
        }
        else
        {
            this->delay += atime;
        }
    }
};

class Beta : public Invader
{
public:
    Beta(float x = 200, float y = 200, int i = 0) : Invader(3.0, i)
    {
        timetoStay = 100;
        this->x = x;
        this->y = y;
        e.loadFromFile("img/enemy_2.png");
        esprite.setTexture(e);
        esprite.setPosition(x, y);
        esprite.setScale(0.5, 0.5);
        this->exists = 1;
        this->attack = nullptr;
        health = 2;
        type = 2;
    }
    void behaviour(float atime) override
    {
        srand(time(0));
        if (this->attack != nullptr)
        {
            if (this->attack->exists == true)
            {
                this->attack->move();
            }
            else if (this->attack->exists == false)
            {
                delete this->attack;
                this->attack = nullptr;
            }
        }
        int randNum = rand() % (4 + this->index) + 1;
        if (this->attack == nullptr && this->delay >= attackInterval && randNum == 1)
        {
            this->attack = new Bomb("img/PNG/Lasers/laserBlue02.png", this->x, this->y, 0, 1);
            this->delay = 0;
        }
        else
        {
            this->delay += atime;
        }
    }
};

class Gamma : public Invader
{
public:
    Gamma(float x = 200, float y = 200, int i = 0) : Invader(3.0, i)
    {
        timetoStay = 100;
        this->x = x;
        this->y = y;
        e.loadFromFile("img/enemy_3.png");
        esprite.setTexture(e);
        esprite.setPosition(x, y);
        esprite.setScale(0.5, 0.5);
        this->exists = 1;
        this->attack = nullptr;
        health = 3;
        type = 3;
    }
    void behaviour(float atime) override
    {
        srand(time(0));
        if (this->attack != nullptr)
        {
            if (this->attack->exists == true)
            {
                this->attack->move();
            }
            else if (this->attack->exists == false)
            {
                delete this->attack;
                this->attack = nullptr;
            }
        }
        int randNum = rand() % (4 + this->index) + 1;
        if (this->attack == nullptr && this->delay >= attackInterval && randNum == 1)
        {
            this->attack = new Bomb("img/PNG/Lasers/laserBlue03.png", this->x, this->y, 0, 1);
            this->delay = 0;
        }
        else
        {
            this->delay += atime;
        }
    }
};