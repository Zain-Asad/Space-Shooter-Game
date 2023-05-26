#include "game.h"
/*This File contains just the coordinates for the spawning of enemies in different shapes;
relevant shapes are randomized based on level and decided on within game itself*/
void rectangle(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(200, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(200, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(200, 100, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(275, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(275, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(275, 100, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(350, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(350, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(350, 100, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(425, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(425, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(425, 100, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(500, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(500, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(500, 100, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(200, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(200, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(200, 200, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(500, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(500, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(500, 200, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(200, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(200, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(200, 300, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(275, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(275, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(275, 300, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(350, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(350, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(350, 300, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(425, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(425, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(425, 300, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(500, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(500, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(500, 300, pos);
        }
        break;
    }
}

void triangle(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 50, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(405, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(405, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(405, 100, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(255, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(255, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(255, 100, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(480, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(480, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(480, 150, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(180, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(180, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(180, 150, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(105, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(105, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(105, 200, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(555, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(555, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(555, 200, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(630, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(630, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(630, 300, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(30, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(30, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(30, 300, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(175, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(175, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(175, 300, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 300, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(485, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(485, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(485, 300, pos);
        }
        break;
    }
}

void cross(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(50, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(50, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(50, 50, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(600, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(600, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(600, 50, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(162.5, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(162.5, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(162.5, 100, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(275, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(275, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(275, 150, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(275, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(275, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(275, 200, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(162.5, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(162.5, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(162.5, 250, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(50, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(50, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(50, 300, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(487.5, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(487.5, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(487.5, 100, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(375, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(375, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(375, 150, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(375, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(375, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(375, 200, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(487.5, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(487.5, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(487.5, 250, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(600, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(600, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(600, 300, pos);
        }
        break;
    }
}

void heart(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 100, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 300, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(230, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(230, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(230, 50, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(430, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(430, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(430, 50, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(530, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(530, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(530, 100, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(130, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(130, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(130, 100, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(180, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(180, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(180, 150, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(480, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(480, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(480, 150, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(230, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(230, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(230, 200, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(430, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(430, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(430, 200, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(280, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(280, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(280, 250, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(380, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(380, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(380, 250, pos);
        }
        break;
    }
}

void diamond(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 0, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 0, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 0, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 300, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(230, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(230, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(230, 50, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(430, 50, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(430, 50, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(430, 50, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(500, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(500, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(500, 100, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(150, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(150, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(150, 100, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(180, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(180, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(180, 150, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(480, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(480, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(480, 150, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(230, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(230, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(230, 200, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(430, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(430, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(430, 200, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(280, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(280, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(280, 250, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(380, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(380, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(380, 250, pos);
        }
        break;
    }
}

void circle(Enemy *&w, int pos)
{
    switch (pos)
    {
    case 0:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 80, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 80, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 80, pos);
        }
        break;
    case 1:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(330, 320, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(330, 320, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(330, 320, pos);
        }
        break;
    case 2:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(400, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(400, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(400, 300, pos);
        }
        break;
    case 3:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(400, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(400, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(400, 100, pos);
        }
        break;
    case 4:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(450, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(450, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(450, 150, pos);
        }
        break;
    case 5:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(430, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(430, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(430, 250, pos);
        }
        break;
    case 6:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(260, 100, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(260, 100, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(260, 100, pos);
        }
        break;
    case 7:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(210, 150, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(210, 150, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(210, 150, pos);
        }
        break;
    case 8:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(180, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(180, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(180, 200, pos);
        }
        break;
    case 9:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(230, 250, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(230, 250, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(230, 250, pos);
        }
        break;
    case 10:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(260, 300, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(260, 300, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(260, 300, pos);
        }
        break;
    case 11:
        if (w->type == 1)
        {
            delete w;
            w = nullptr;
            w = new Alpha(470, 200, pos);
        }
        else if (w->type == 2)
        {
            delete w;
            w = nullptr;
            w = new Beta(470, 200, pos);
        }
        else if (w->type == 3)
        {
            delete w;
            w = nullptr;
            w = new Gamma(470, 200, pos);
        }
        break;
    }
}
