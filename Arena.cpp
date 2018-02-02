#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <sstream>


//other 
bool Arena::addFighter(std::string info) {
	std::stringstream input;
	std::string name;
	char type;
	int maximumHP = 0;
	int strength = 0;
	int speed = 0;
	int magic = 0;
	std::string extra;

	input << info;

	while (input >> name >> type >> maximumHP >> strength >> speed >> magic) {
		if (input >> extra) {
			return false;
		}
		for (int i = 0; i < fighters.size(); ++i) {
			if (name == fighters.at(i)->getName()) {
				return false;
			}
		}
		if (type == 'A') {
			fighters.push_back(new Archer(name, maximumHP, strength, speed, magic));
		}

		else if (type == 'C') {
			fighters.push_back(new Cleric(name, maximumHP, strength, speed, magic));
		}

		else if (type == 'R') {
			fighters.push_back(new Robot(name, maximumHP, strength, speed, magic));
		}
		return true;
	}
	return false;
}
	

bool Arena::removeFighter(std::string name) {
	FighterInterface* temp;
	for (int i = 0; i < fighters.size(); ++i) {
		if (name == fighters.at(i)->getName()) {
			temp = fighters.at(i);
			delete temp;
			fighters.erase(fighters.begin() + i);

			return true;
		}
		return false;
	}
}

FighterInterface* Arena::getFighter(std::string name) {
	for (int i = 0; i < fighters.size(); ++i) {
		if (name == fighters.at(i)->getName()) {
			return fighters.at(i);
		}
	}
}

		//getter
int Arena::getSize() const {
	return fighters.size();
}
	