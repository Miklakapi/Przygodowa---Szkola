#pragma once

#include <iostream>
#include <string>

using namespace std;

class Monster{

	string name;	//Monster name
	int hp;			//Monster health
	int attack;		//Monster attack
	int exp;		//Monster exp

public:

	class Data {

		string name;	//Monster name
		int hp;			//Monster health
		int attack;		//Monster attack
		int exp;		//Monster exp

	public:

		Data(string name, int hp, int attack, int exp);

		string asName(bool info);
		int asHp(bool info);
		int asAttack(bool info);
		int asExp(bool info);
		void getAll();
	};

	Monster(string name, int hp, int attack, int exp);

	Monster();

	void setName(string name);

	void setHp(int hp);

	void setAttack(int attack);

	void setExp(int exp);

	Data getData();
};