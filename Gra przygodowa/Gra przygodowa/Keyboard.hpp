#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Vectors.hpp"
#include "Vectors.hpp"

using namespace std;

class Keyboard{

private:

	Vector2i position;

	Vector2i size;

public:

	Keyboard(Vector2i position, Vector2i size);

	Vector2i getPosition();

	Vector2i getSize();

	void start();

	string options(string choice);

	void clear();
};