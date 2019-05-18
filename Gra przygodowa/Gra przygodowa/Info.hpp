#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include "Monster.hpp"
#include "Vectors.hpp"

using namespace std;

class Info{

	Vector2i position;

	Vector2i size;

public:

	Info(Vector2i position, Vector2i size);

	Vector2i getPosition();

	Vector2i getSize();

	void start();

	void draw(Monster& monster);

	bool draw(string text);

	void clear();
};

