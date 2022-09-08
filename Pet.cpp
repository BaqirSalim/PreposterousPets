#include "Pet.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//constructor that intitializes all the variables of the pet class
Pet::Pet() {
	level = 1;
	exp = 0.0;
	expThreshold = 10.0;
	percentHappy = 50.0;
	percentHungry = 50.0;
	percentSleepy = 50.0;
	percentBored = 50.0;
	happyRate.increase = .1;
	happyRate.decrease = .05;
	hungryRate.increase = .1;
	hungryRate.decrease = .05;
	sleepyRate.increase = .1;
	sleepyRate.decrease = .05;
	boredRate.increase = .1;
	boredRate.decrease = .05;
}

//random number generator for #'s 0-2, needed in all derived classes so it lives in the base class
int Pet::generateRandom() {
	srand(static_cast<unsigned int>(time(0)));

	int random = rand() % 3;

	return random;
}

//returns name of the pet
string Pet::getName() {
	return name;
}

//helper function that is used to adjust stats
void Pet::changeStatsHelper(string status, string direction) {

	if (status == "Happy") {
		if (direction == "Increase") {
			if ((percentHappy + (percentHappy * happyRate.increase)) <= 100.0) {
				percentHappy += (percentHappy * happyRate.increase);
			}
			else {
				percentHappy = 100.0;
			}
		}
		else if(direction == "Decrease") {
			if ((percentHappy - (percentHappy * happyRate.decrease)) > 0.0) {
				percentHappy -= (percentHappy * happyRate.decrease);
			}
			else {
				percentHappy = 0.0;
			}
		}
	}
	if (status == "Hungry") {
		if (direction == "Increase") {
			if ((percentHungry + (percentHungry * hungryRate.increase)) <= 100.0) {
				percentHungry += (percentHungry * hungryRate.increase);
			}
			else {
				percentHungry = 100.0;
			}
		}
		else if (direction == "Decrease") {
			if ((percentHungry - (percentHungry * hungryRate.decrease)) >= 0.0) {
				percentHungry -= (percentHungry * hungryRate.decrease);
			}
			else {
				percentHungry = 0.0;
			}
		}
	}
	if (status == "Sleepy") {
		if (direction == "Increase") {
			if ((percentSleepy + (percentSleepy * sleepyRate.increase)) <= 100.0) {
				percentSleepy += (percentSleepy * sleepyRate.increase);
			}
			else {
				percentSleepy = 100.0;
			}
		}
		else if (direction == "Decrease") {
			if ((percentSleepy - (percentSleepy * sleepyRate.decrease)) >= 0.0) {
				percentSleepy -= (percentSleepy * sleepyRate.decrease);
			}
			else {
				percentSleepy = 0.0;
			}
		}
	}
	if (status == "Bored") {
		if (direction == "Increase") {
			if ((percentBored + (percentBored * boredRate.increase)) <= 100.0) {
				percentBored += (percentBored * boredRate.increase);
			}
			else {
				percentBored = 100.0;
			}
		}
		else if (direction == "Decrease") {
			if ((percentBored - (percentBored * boredRate.decrease)) >= 0.0) {
				percentBored -= (percentBored * boredRate.decrease);
			}
			else {
				percentBored = 0.0;
			}
		}
	}

}

//function that checks whether the pet is ready to level up
void Pet::levelUp() {

	if (exp >= expThreshold) {
		level++;
		exp = 0;
		cout << name << " leveled up to level " << level << "!" << endl;
		expThreshold += expThreshold * .1 * level;
	}

}

//function that distributes experience depending on the action passed into it
void Pet::distributeExp(string action) {
	if (action == "play") {
		exp += expThreshold * .25;
	}
	else if (action == "feed") {
		exp += expThreshold * .15;
	}
	else if (action == "sleep") {
		exp += expThreshold * .1;
	}
	else if (action == "walk") {
		exp += expThreshold * .2;
	}
	levelUp();
}

//function that prints out all the pet's stats
void Pet::printStatus() {
	cout << fixed << setprecision(3);
	cout << "------------------------------------------------------------" << endl;
	cout << name << "'s Stats:" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Level: " << level << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Exp: " << exp << endl;
	cout << "Exp Threshold: " << expThreshold << endl;
	cout << "Exp to next level: " << expThreshold - exp << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Happiness: " << percentHappy << "%" << endl;
	cout << "Hungriness: " << percentHungry << "%" << endl;
	cout << "Sleepiness: " << percentSleepy << "%" << endl;
	cout << "Boredness: " << percentBored << "%" << endl;
}

//function that sets the name of the pet
void Pet::setName(string _name) {
	name = _name;
}

//save function that returns a boolean that tells whether or not the save was successful
bool Pet::save(string fileName) {
	ofstream saveFile;
	if (fileName == "NA") {
		string newFileName = name + "s_save_file";
		saveFile.open(newFileName);

		cout << "The name of your new save file is: " << newFileName << endl;
	}
	else {
		ofstream test(fileName, std::fstream::in);
		if (test.is_open()) {
			test.close();
			saveFile.open(fileName);
		}
		else {
			return false;
		}
	}
		saveFile << name << endl;
		saveFile << level << endl;
		saveFile << exp << endl;
		saveFile << expThreshold << endl;
		saveFile << percentHappy << endl;
		saveFile << percentHungry << endl;
		saveFile << percentSleepy << endl;
		saveFile << percentBored << endl;
		saveFile << happyRate.increase << endl;
		saveFile << happyRate.decrease << endl;
		saveFile << hungryRate.increase << endl;
		saveFile << hungryRate.decrease << endl;
		saveFile << sleepyRate.increase << endl;
		saveFile << sleepyRate.decrease << endl;
		saveFile << boredRate.increase << endl;
		saveFile << boredRate.decrease << endl;
		saveFile.close();
		return true;

}

//load function that returns a boolean that tells whether or not the load was successful
bool Pet::load(string fileName) {

	ifstream loadFile;
	ifstream test(fileName, std::fstream::in);
	if (test.is_open()) {
		test.close();
		loadFile.open(fileName);
	}
	else {
		return false;
	}
	getline(loadFile, name);
	loadFile >> level >> exp >> expThreshold >> percentHappy >> percentHungry >> percentSleepy >> percentBored;
	loadFile >> happyRate.increase >> happyRate.decrease >> hungryRate.increase >> hungryRate.decrease >> sleepyRate.increase;
	loadFile >> sleepyRate.decrease >> boredRate.increase >> boredRate.decrease;

	loadFile.close();
	return true;
}

//time passage function that changes the stats and does checks to tell user if a stat is particularly low
void Pet::nextHour() {
	changeStatsHelper("Happy", "Decrease");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Bored", "Increase");
	changeStatsHelper("Sleepy", "Increase");

	cout << "One hour has passed." << endl;
	printStatus();

	if (percentHungry > 50) {
		cout << name << " is hungry! \nMake sure to feed them!" << endl;
	}
	if (percentBored > 55) {
		cout << name << " is bored! \nMake sure to play with them!" << endl;
	}
	if (percentHappy < 30) {
		cout << name << " isn't happy! \nDo something with them to change that!" << endl;
	}
	if (percentSleepy > 65) {
		cout << name << "  is sleepy! \nMake sure to put them to sleep!" << endl;
	}
}