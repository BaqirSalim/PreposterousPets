#include "Dragon.h"

//constructor that assigns all variables dragon specific stats
Dragon::Dragon() {
	percentHappy = 35.0;
	percentHungry = 65.0;
	percentSleepy = 50.0;
	percentBored = 10.0;
	happyRate.increase = .15;
	happyRate.decrease = .07;
	hungryRate.increase = .18;
	hungryRate.decrease = .4;
	sleepyRate.increase = .25;
	sleepyRate.decrease = .45;
	boredRate.increase = .4;
	boredRate.decrease = .25;
}

//play function that prints dragon specific statements and adjusts stats, distributes experience, and prints out stats
void Dragon::play() {
	//increase, happiness, hungriness, and sleepiness. decrease boredom
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You took " << name << " for a flight!" << endl;
	}
	else if (printLine == 1) {
		cout << "You took " << name << " for a swim!" << endl;
	}
	else if (printLine == 2) {
		cout << "You took " << name << " to the nearby town to torment the civilians!" << endl;
	}

	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Bored", "Decrease");

	distributeExp("play");
	printStatus();
}

//feed function that prints dragon specific statements and adjusts stats, distributes experience, and prints out stats
void Dragon::feed() {
	//decrease hungriness. increase sleepiness and happiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You fed " << name << " an elephant!" << endl;
	}
	else if (printLine == 1) {
		cout << "You fed " << name << " a whale!" << endl;
	}
	else if (printLine == 2) {
		cout << "You fed " << name << " cows!" << endl;
	}

	changeStatsHelper("Hungry", "Decrease");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Happy", "Increase");

	distributeExp("feed");
	printStatus();
}

//sleep function that prints dragon specific statements and adjusts stats, distributes experience, and prints out stats
void Dragon::sleep() {
	//decrease sleepiness. Increase boredom and hungriness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "Woah! " << name << " is tuckered out!" << endl;
	}
	else if (printLine == 1) {
		cout << "You brought " << name << " back to his cave and put him to sleep!" << endl;
	}
	else if (printLine == 2) {
		cout << " Uh oh! " << name << " burned off a piece of your hair while he snored!" << endl;
	}

	changeStatsHelper("Sleepy", "Decrease");
	changeStatsHelper("Bored", "Increase");
	changeStatsHelper("Hungry", "Increase");

	distributeExp("sleep");
	printStatus();
}

//walk function that prints dragon specific statements and adjusts stats, distributes experience, and prints out stats
void Dragon::walk() {
	//decrease boredom. Increase hungriness, happiness, and sleepiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You better catch up to " << name << ", they're getting pretty far away!" << endl;
	}
	else if (printLine == 1) {
		cout << "You hopped on " << name << "'s back and went for a walk!" << endl;
	}
	else if (printLine == 2) {
		cout << name << " walks beside you!" << endl;
	}

	changeStatsHelper("Bored", "Decrease");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Sleepy", "Increase");

	distributeExp("walk");
	printStatus();
}