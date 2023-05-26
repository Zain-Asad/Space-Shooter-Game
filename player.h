#include <SFML/Graphics.hpp>
#include <string.h>
#include "AddOns.h"
using namespace sf;
using namespace std;

class Bullet
{
public:
	float x;
	float y;
	float delx;
	float dely;
	float speed;
	bool exists;
	Texture bul;
	Sprite bulsprite;
	Bullet(string png_path, float x, float y, float delx, float dely)
	{
		bul.loadFromFile(png_path);
		bulsprite.setTexture(bul);
		this->x = x;
		this->y = y;
		this->delx = delx;
		this->dely = dely;
		speed = 10;
		exists = true;
		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
		{
			bulsprite.setScale(2.2, 2.2);
			bulsprite.setPosition(x + 50, y);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
		{
			bulsprite.setScale(2.2, 2.2);
			bulsprite.setPosition(x, y);
		}
		else
		{
			bulsprite.setScale(0.5, 0.5);
			bulsprite.setPosition(x + 50, y);
		}
	}
	Bullet(string png_path, float x, float y, float delx, float dely, float s)
	{
		bul.loadFromFile(png_path);
		bulsprite.setTexture(bul);
		this->x = x;
		this->y = y;
		this->delx = delx;
		this->dely = dely;
		speed = 5;
		exists = true;
		bulsprite.setScale(0.75 + s, 0.75 + s);
		bulsprite.setPosition(x + 50, y);
	}

	void move()
	{
		if (exists)
		{
			if (this->y >= 0 && x <= 720 && x >= -720)
			{
				y += dely * speed;
				x += delx * speed;
				bulsprite.move(delx * speed, dely * speed);
			}
			else
			{
				exists = false;
			}
		}
	}
};

class Player
{
public:
	Texture tex;
	Texture lt;
	Sprite sprite;
	Sprite dLives;
	float speed;
	float x, y;
	bool canFire;
	int lives;
	Bullet *shoot;

	bool isFire;
	bool power;

	Player(std::string png_path)
	{
		speed = 1.0;
		tex.loadFromFile(png_path);
		lt.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 320;
		y = 850;
		sprite.setPosition(x, y);
		sprite.setScale(1.1, 1.1);
		canFire = true;
		shoot = nullptr;
		isFire = false;
		power = false;
		lives = 3;
		dLives.setTexture(lt);
		dLives.setPosition(10, 950);
		dLives.setScale(0.5, 0.5);
	}

	void fire()
	{
		if (canFire == true)
		{
			if (!power)
			{
				if (!isFire)
				{
					if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
					{
						shoot = new Bullet("img/PNG/Lasers/laserGreen02UR.png", this->x, this->y, 1, -1);
						canFire = false;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
					{
						shoot = new Bullet("img/PNG/Lasers/laserGreen02UL.png", this->x, this->y, -1, -1);
						canFire = false;
					}
					else
					{
						shoot = new Bullet("img/PNG/Lasers/laserGreen02.png", this->x, this->y, 0, -1);
						canFire = false;
					}
				}
				else if (isFire)
				{
					if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
					{
						shoot = new Bullet("img/fire.png", this->x, this->y, 1, -1, 0.5);
						canFire = false;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
					{
						shoot = new Bullet("img/fire.png", this->x, this->y, -1, -1, 0.5);
						canFire = false;
					}
					else
					{
						shoot = new Bullet("img/fire.png", this->x, this->y, 0, -1, 0.5);
						canFire = false;
					}
				}
			}
			else if (power && !isFire)
			{
				shoot = new Bullet[7]{Bullet("img/PNG/Lasers/laserGreen02UL.png", this->x, this->y, -1.25, -1, 0.5), Bullet("img/PNG/Lasers/laserGreen02UL.png", this->x, this->y, -0.85, -1, 0.5), Bullet("img/PNG/Lasers/laserGreen02UL.png", this->x, this->y, -0.5, -1, 0.5), Bullet("img/PNG/Lasers/laserGreen02.png", this->x, this->y, 0, -1, 0), Bullet("img/PNG/Lasers/laserGreen02UR.png", this->x, this->y, 0.5, -1, 0.5), Bullet("img/PNG/Lasers/laserGreen02UR.png", this->x, this->y, 0.85, -1, 0.5), Bullet("img/PNG/Lasers/laserGreen02UR.png", this->x, this->y, 1.25, -1, 0.5)};
				canFire = false;
			}
			else if (power && isFire)
			{
				shoot = new Bullet[7]{Bullet("img/fire.png", this->x, this->y, -1.25, -1, 0.5), Bullet("img/fire.png", this->x, this->y, -0.85, -1, 0.5), Bullet("img/fire.png", this->x, this->y, -0.5, -1, 0.5), Bullet("img/fire.png", this->x, this->y, 0, -1, 0.5), Bullet("img/fire.png", this->x, this->y, 0.5, -1, 0.5), Bullet("img/fire.png", this->x, this->y, 0.85, -1, 0.5), Bullet("img/fire.png", this->x, this->y, 1.25, -1, 0.5)};
				canFire = false;
			}
		}
	}
	void playerbullet()
	{
		bool check = false;
		if (shoot != nullptr)
		{
			if (power == false)
			{
				if (shoot->exists)
				{
					shoot->move();
				}
				else
				{
					canFire = true;
					delete shoot;
					shoot = nullptr;
				}
			}
			else if (power)
			{
				for (int i = 0; i < 7; i++)
				{
					if (shoot[i].exists)
					{
						shoot[i].move();
					}
					else
					{
						check = true;
					}
				}
				if (check)
				{
					for (int i = 0; i < 7; i++)
					{
						if (shoot[i].exists == true)
							return;
					}
					delete[] shoot;
					shoot = nullptr;
					canFire = true;
				}
			}
		}
	}
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
		{
			if (x >= -70)
			{
				delta_x = -1;
				delta_x *= speed;
			}
			else
			{
				delta_x = 710;
			}
		}
		else if (s == "r")
		{
			if (x <= 650)
			{
				delta_x = 1;
				delta_x *= speed;
			}
			else
			{
				delta_x = -710;
			}
		}
		if (s == "u")
		{
			if (y >= 200)
			{
				delta_y = -1;
				delta_y *= speed;
			}
		}
		else if (s == "d")
		{
			if (y <= 850)
			{
				delta_y = 1;
				delta_y *= speed;
			}
		}

		x += delta_x;
		y += delta_y;
		sprite.move(delta_x, delta_y);
	}
};
