#include "Keyboard.hpp"

Keyboard::Keyboard(Vector2i position, Vector2i size){
	this->position = position;
	this->size = size;
}

Vector2i Keyboard::getPosition() {
	return position;
}

Vector2i Keyboard::getSize() {
	return size;
}

void Keyboard::start() {
	_COORD coord;
	coord.X = position.x;
	coord.Y = position.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = position.x; i < position.x + size.x; i++) {
		cout << "#";
		Sleep(65);
	}
	coord.X = position.x + size.x - 1;
	for (int i = position.y + 1; i < position.y + size.y; i++) {
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "#";
		Sleep(65);
	}
	coord.Y = position.y + size.y - 1;
	for (int i = position.x + size.x - 2; i >= position.x; i--) {
		coord.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "#";
		Sleep(65);
	}
	coord.X = position.x;
	for (int i = position.y + size.y - 2; i > position.y; i--) {
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "#";
		Sleep(65);
	}
}

void Keyboard::clear() {
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

void gotoxy(int x, int y) {
	_COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string Keyboard::options(string choice) {
	clear();
	char c = '0';
	int opt(1);

	if (choice == "start") {
		gotoxy(position.x + 8, position.y + 4);
		cout << "GRAJ";
		gotoxy(position.x + 8, position.y + 8);
		cout << "WYJDZ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		while (c != char(13)) {

			if (opt == 1) {
				gotoxy(position.x + 4, position.y + 4);
				cout << "->";
				gotoxy(position.x + 14, position.y + 4);
				cout << "<-";
			}
			else {
				gotoxy(position.x + 4, position.y + 8);
				cout << "->";
				gotoxy(position.x + 14, position.y + 8);
				cout << "<-";
			}
			gotoxy(0, 0);

			c = _getch();
			if (c == 'w' || c == 's') {
				if (opt == 1) {
					gotoxy(position.x + 4, position.y + 4);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 4);
					cout << "  ";
					opt = 2;
				}
				else {
					gotoxy(position.x + 4, position.y + 8);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 8);
					cout << "  ";
					opt = 1;
				}
			}

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (opt == 2) {
			exit(0);
		}
		else return "play";
	}
	else if (choice == "play") {
		gotoxy(position.x + 8, position.y + 4);
		cout << "GORA";
		gotoxy(position.x + 8, position.y + 6);
		cout << "LEWO";
		gotoxy(position.x + 8, position.y + 8);
		cout << "PRAWO";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		while (c != char(13)) {

			if (opt == 1) {
				gotoxy(position.x + 4, position.y + 4);
				cout << "->";
				gotoxy(position.x + 14, position.y + 4);
				cout << "<-";
			}
			else if (opt == 2) {
				gotoxy(position.x + 4, position.y + 6);
				cout << "->";
				gotoxy(position.x + 14, position.y + 6);
				cout << "<-";
			}
			else {
				gotoxy(position.x + 4, position.y + 8);
				cout << "->";
				gotoxy(position.x + 14, position.y + 8);
				cout << "<-";
			}
			gotoxy(0, 0);

			c = _getch();
			if (c == 'w'){
				if (opt == 1) {
					gotoxy(position.x + 4, position.y + 4);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 4);
					cout << "  ";
					opt = 3;
				}
				else if (opt == 2) {
					gotoxy(position.x + 4, position.y + 6);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 6);
					cout << "  ";
					opt = 1;
				}
				else {
					gotoxy(position.x + 4, position.y + 8);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 8);
					cout << "  ";
					opt = 2;
				}
			}
			else if (c == 's') {
				if (opt == 1) {
					gotoxy(position.x + 4, position.y + 4);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 4);
					cout << "  ";
					opt = 2;
				}
				else if (opt == 2) {
					gotoxy(position.x + 4, position.y + 6);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 6);
					cout << "  ";
					opt = 3;
				}
				else {
					gotoxy(position.x + 4, position.y + 8);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 8);
					cout << "  ";
					opt = 1;
				}
			}

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		return to_string(opt);
	}
	else if (choice == "monster") {
		gotoxy(position.x + 7, position.y + 4);
		cout << "WALCZ";
		gotoxy(position.x + 7, position.y + 8);
		cout << "UCIEKAJ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		while (c != char(13)) {

			if (opt == 1) {
				gotoxy(position.x + 4, position.y + 4);
				cout << "->";
				gotoxy(position.x + 14, position.y + 4);
				cout << "<-";
			}
			else {
				gotoxy(position.x + 4, position.y + 8);
				cout << "->";
				gotoxy(position.x + 14, position.y + 8);
				cout << "<-";
			}
			gotoxy(0, 0);

			c = _getch();
			if (c == 'w' || c == 's') {
				if (opt == 1) {
					gotoxy(position.x + 4, position.y + 4);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 4);
					cout << "  ";
					opt = 2;
				}
				else {
					gotoxy(position.x + 4, position.y + 8);
					cout << "  ";
					gotoxy(position.x + 14, position.y + 8);
					cout << "  ";
					opt = 1;
				}
			}

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (opt == 1) {
			return "walcz";
		}
		else {
			return "uciekaj";
		}
	}
}