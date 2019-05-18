#include "Player.hpp"

Player::Player(string name, int hp, int attack, int lv, int exp, int rExp) {
	setName(name);
	setHp(hp);
	setLv(lv);
	setExp(exp);
	setRExp(rExp);
	setAttack(attack);
}

Player::Player(){
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setHp(int hp) {
	if (hp < 0) this->hp = 0;
	else this->hp = hp;
}

void Player::setLv(int lv) {
	if (lv < 0) this->lv = 1;
	else this->lv = lv;
}

void Player::setExp(int exp) {
	this->exp = exp;
}

void Player::setRExp(int rExp) {
	this->rExp = rExp;
}

void Player::setAttack(int attack) {
	this->attack = attack;
}

void Player::nextLv() {
	setExp(exp - rExp);
	setHp(int(hp * 1.10));
	setAttack(int(attack * 1.10));
	setRExp(int(rExp * 1.40));
	setLv(++lv);
}

Player::Data Player::getData() {
	return Data(name, hp, attack, lv, exp, rExp);
}

//-----------------

Player::Data::Data(string name, int hp, int attack, int lv, int exp, int rExp) {
	this->name = name;
	this->hp = hp;
	this->attack = attack;
	this->lv = lv;
	this->exp = exp;
	this->rExp = rExp;
}

string Player::Data::asName(bool info) {
	if (info) cout << "Name: " << name << endl;
	return name;
}

int Player::Data::asHp(bool info) {
	if (info) cout << "Hp: " << hp << endl;
	return hp;
}

int Player::Data::asAttack(bool info) {
	if (info) cout << "Attack: " << attack << endl;
	return attack;
}

int Player::Data::asLv(bool info) {
	if (info) cout << "Lv: " << lv << endl;
	return lv;
}

int Player::Data::asExp(bool info) {
	if (info) cout << "Exp: " << exp << endl;
	return exp;
}

int Player::Data::asRExp(bool info) {
	if (info) cout << "Require Exp: " << rExp << endl;
	return rExp;
}

void Player::Data::getAll(bool info) {
	cout << "Name: " << name << endl;
	cout << "Hp: " << hp << endl;
	cout << "Lv: " << lv << endl;
	cout << "Attack: " << attack << endl;
	cout << "Exp: " << exp << endl;
	cout << "Require Exp: " << rExp << endl;
}