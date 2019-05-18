#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include "Statistic.hpp"
#include "Info.hpp"
#include "Keyboard.hpp"
#include "Monsters.hpp"
#include "Player.hpp"

using namespace std;

int main() {

	srand(time(NULL));

	Player player{ "Player",100,15,1,0,20 };
	Monsters monsters{ 8 };
	monsters.random();

	Keyboard keyboard{ Vector2i{24,10},Vector2i{20,13} };
	Statistic stat{ Vector2i{5,10},Vector2i{19,13} };
	Info info{ Vector2i{44,10},Vector2i{19,13} };

	keyboard.start();
	keyboard.options("start");
	keyboard.clear();
	
	stat.start();
	stat.draw(player);

	info.start();

	//

	int round(1);
	bool fight(false);
	string option;

	//

	while (round <= 15 && player.getData().asHp(false) > 0) {
		stat.draw(player);
		if (((rand() % 3) + 1) == atoi(keyboard.options("play").c_str())) {
			info.draw("znaleziono");
			Sleep(1500);
			
			Monster* monster = monsters.getRandomMob();
			info.draw(*monster);
			option = keyboard.options("monster");
			
			if (option == "uciekaj" && (rand() % 2)) {
				info.draw("ucieczka");
			}
			else if(option == "uciekaj"){
				info.draw("!ucieczka");
				fight = true;
				Sleep(1500);
			}
			else {
				fight = true;
			}

			if (fight) {

				do {

					monster->setHp(monster->getData().asHp(false) - player.getData().asAttack(false));
					player.setHp(player.getData().asHp(false) - monster->getData().asAttack(false));

				} while (player.getData().asHp(false) > 0 && monster->getData().asHp(false) > 0);

				if (player.getData().asHp(false) > 0) {
					player.setExp(player.getData().asExp(false) + monster->getData().asExp(false));
					while (player.getData().asExp(false) >= player.getData().asRExp(false)) { player.nextLv(); }
					stat.draw(player);
					info.draw("pokonano");
				}

				fight = false;
			}
		}
		else {
			info.draw("!znaleziono");
		}

		round++;
	}
	if (player.getData().asHp(false) > 0) {
		keyboard.clear();
		info.draw("wygrano");
	}
	else {
		info.draw("przegrano");
	}
	_COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	cin.get();
}