#include "Statistic.hpp"

Statistic::Statistic(Vector2i position, Vector2i size) {
	this->position = position;
	this->size = size;
}


Vector2i Statistic::getPosition() {
	return position;
}

Vector2i Statistic::getSize() {
	return size;
}

void Statistic::start() {
	_COORD coord;
	coord.Y = position.y;
	for (int i = size.x + position.x - 1; i >= position.x; i--) {
		coord.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
	coord.X = position.x;
	for (int i = position.y + 1; i <= position.y + size.y - 1; i++) {
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
	coord.Y = position.y + size.y - 1;
	for (int i = position.x + 1; i < position.x + size.x; i++) {
		coord.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
}

void Statistic::draw(Player& player) {
	clear();
	_COORD coord;
	coord.X = position.x + 2;
	coord.Y = position.y + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asName(true);
	//
	coord.Y = position.y + 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asHp(true);
	//
	coord.Y = position.y + 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asAttack(true);
	//
	coord.Y = position.y + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asLv(true);
	//
	coord.Y = position.y + 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asExp(true);
	//
	coord.Y = position.y + 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	player.getData().asRExp(true);
}

void Statistic::clear() {
	_COORD coord;
	for (int x = position.x + 1; x < position.x + size.x - 1; x++) {
		coord.X = x;
		for (int y = position.y + 1; y < position.y + size.y - 1; y++) {
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << " ";
		}
	}
}