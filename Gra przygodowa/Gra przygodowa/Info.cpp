#include "Info.hpp"

Info::Info(Vector2i position, Vector2i size){
	this->position = position;
	this->size = size;
}

Vector2i Info::getPosition() {
	return position;
}

Vector2i Info::getSize() {
	return size;
}

void Info::start() {
	_COORD coord;
	coord.Y = position.y;
	for (int i = position.x; i < position.x + size.x; i++) {
		coord.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
	coord.X = position.x + size.x - 1;
	for (int i = position.y + 1; i < position.y + size.y; i++) {
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
	coord.Y = position.y + size.y - 1;
	for (int i = position.x + size.x - 2; i >= position.x; i--) {
		coord.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << '#';
		Sleep(65);
	}
}

void Info::draw(Monster& monster) {
	clear();
	_COORD coord;
	coord.X = position.x + 2;
	coord.Y = position.y + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	monster.getData().asName(true);
	//
	coord.Y = position.y + 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	monster.getData().asHp(true);
	//
	coord.Y = position.y + 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	monster.getData().asAttack(true);
	//
	coord.Y = position.y + 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	monster.getData().asExp(true);
}

bool Info::draw(string text) {
	clear();
	_COORD coord;
	coord.X = position.x + 2;
	coord.Y = position.y + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	if (text == "ucieczka") {
		cout << "Udalo ci sie";
		coord.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "uciec.";
	}
	else if (text == "!ucieczka") {
		cout << "Nie udalo ci";
		coord.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "sie uciec.";
	}
	else if (text == "znaleziono") {
		cout << "Znaleziono";
		coord.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "potowra.";
	}
	else if (text == "!znaleziono") {
		cout << "Nie znaleziono";
		coord.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "potowra.";
	}
	else if (text == "pokonano") {
		cout << "Pokonano";
		coord.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "potowra.";
	}
	else if (text == "przegrano") {
		cout << "Przegrales.";
	}
	else if (text == "wygrano") {
		cout << "Wygrales.";
	}
	else {
		return false;
	}
	return true;
}

void Info::clear() {
	_COORD coord;
	for (int x = position.x; x < position.x + size.x - 1; x++) {
		coord.X = x;
		for (int y = position.y + 1; y < position.y + size.y - 1; y++) {
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << " ";
		}
	}
}