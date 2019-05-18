#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include "Player.hpp"
#include "Vectors.hpp"

using namespace std;

class Statistic{

	Vector2i position;

	Vector2i size;

public:

	Statistic(Vector2i position, Vector2i size);
	
	Vector2i getPosition();

	Vector2i getSize();

	void start();

	void draw(Player& player);

	void clear();
};