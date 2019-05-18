#pragma once

#include <iostream>
#include <string>
#include "Monster.hpp"

using namespace std;

class Monsters{

	Monster* monster;
	int monsterNr;

public:

	Monsters(int monsterNr);

	int getMonsterNr();

	Monster getMonster(int nr);

	Monster* getMonsters();

	Monster* getRandomMob();

	void random();

	void reset();

	~Monsters();
};