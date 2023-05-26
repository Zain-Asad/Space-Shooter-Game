#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
using namespace std;

class AddOns
{
public:
    int type;
    Texture texture;
    Sprite asprite;
    float x;
    float y;
    float speed;

    AddOns(int t, const std::string &pngpath, float x, float y, float s)
    {
        type = t;
        texture.loadFromFile(pngpath);
        asprite.setTexture(texture);
        this->x = x;
        this->y = y;
        speed = s;
        asprite.setPosition(x, y);
    }

    void move()
    {
        if (y <= 900)
            y += speed;
        asprite.setPosition(x, y);
    }
};