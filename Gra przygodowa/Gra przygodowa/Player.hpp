#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player{

	string name;	//player name
	int hp;			//player health
	int attack;		//Player attack
	int lv;			//player level
	int exp;		//player exp
	int rExp;		//require exp

public:

	class Data {

		string name;	//player name
		int hp;			//player health
		int attack;		//Player attack
		int lv;			//player level
		int exp;		//player exp
		int rExp;		//require exp

	public:

		Data(string name, int hp, int attack, int lv, int exp, int rExp);

		string asName(bool info);
		int asHp(bool info);
		int asAttack(bool info);
		int asLv(bool info);
		int asExp(bool info);
		int asRExp(bool info);
		void getAll(bool info);
	};

	Player(string name, int hp, int attack, int lv, int exp, int rExp);
	
	Player();

	void setName(string name);

	void setHp(int hp);

	void setLv(int lv);

	void setExp(int exp);

	void setRExp(int rExp);

	void setAttack(int attack);

	void nextLv();

	Data getData();
};

