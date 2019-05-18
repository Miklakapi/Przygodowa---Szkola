#include "Monsters.hpp"

Monsters::Monsters(int monsterNr) {
	if (monsterNr < 0) this->monsterNr = 1;
	else this->monsterNr = monsterNr;

	monster = new Monster[monsterNr];
}

int Monsters::getMonsterNr() {
	return monsterNr;
}

Monster Monsters::getMonster(int nr) {
	return *(monster + nr);
}

Monster* Monsters::getMonsters() {
	return monster;
}

Monster* Monsters::getRandomMob() {
	int ra;
	do {
		ra = rand() % monsterNr;
	} while ((monster+ra)->getData().asHp(false) == 0);
	return (monster + ra);
}

void Monsters::random() {
	for (int i = 0; i < monsterNr; i++) {
		(monster + i)->setAttack(int(rand() % 25 + 1));
		(monster + i)->setHp(int(rand() % 50 + 1));
		(monster + i)->setExp((monster + i)->getData().asAttack(false) + (monster + i)->getData().asHp(false));
		(monster + i)->setName("Monster");
	}
}

void Monsters::reset() {
	random();
}

Monsters::~Monsters() {
	delete [] monster;
}