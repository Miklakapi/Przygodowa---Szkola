#include "Monster.hpp"

Monster::Monster(string name, int hp, int attack, int exp) {
	setName(name);
	setHp(hp);
	setAttack(attack);
	setExp(exp);
}

Monster::Monster() {
}

void Monster::setName(string name) {
	this->name = name;
}

void Monster::setHp(int hp) {
	if (hp < 0) this->hp = 0;
	else this->hp = hp;
}

void Monster::setAttack(int attack) {
	if (attack < 0) this->attack = 0;
	else this->attack = attack;
}

void Monster::setExp(int exp) {
	this->exp = exp;
}

Monster::Data Monster::getData() {
	return Data(name, hp, attack, exp);
}

//-----------------

Monster::Data::Data(string name, int hp, int attack, int exp) {
	this->name = name;
	this->hp = hp;
	this->attack = attack;
	this->exp = exp;
}

string Monster::Data::asName(bool info) {
	if (info) cout << "Name: " << name << endl;
	return name;
}

int Monster::Data::asHp(bool info) {
	if (info) cout << "Hp: " << hp << endl;
	return hp;
}

int Monster::Data::asAttack(bool info) {
	if (info) cout << "Attack: " << attack << endl;
	return attack;
}

int Monster::Data::asExp(bool info) {
	if (info) cout << "Exp: " << exp <<endl;
	return exp;
}

void Monster::Data::getAll() {
	cout << "Name: " << name << endl;
	cout << "Hp: " << hp << endl;
	cout << "Attack: " << attack << endl;
	cout << "Exp: " << exp << endl;
}