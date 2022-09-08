#include "Penguin.h"

//constructor that assigns all variables penguin specific stats
Penguin::Penguin() {
	percentHappy = 80.0;
	percentHungry = 30.0;
	percentSleepy = 55.0;
	percentBored = 25.0;
	happyRate.increase = .2;
	happyRate.decrease = .05;
	hungryRate.increase = .15;
	hungryRate.decrease = .2;
	sleepyRate.increase = .1;
	sleepyRate.decrease = .2;
	boredRate.increase = .3;
	boredRate.decrease = .15;
}

//play function that prints penguin specific statements and adjusts stats, distributes experience, and prints out stats
void Penguin::play() {
	//increase, happiness, hungriness, and sleepiness. decrease boredom
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You went sledding with " << name << "!" << endl;
	}
	else if (printLine == 1) {
		cout << "You played in the snow with " << name << "!" << endl;
	}
	else if(printLine == 2) {
		cout << "You took " << name << " to the zoo! Hey why are there other penguins in there?" << endl;
	}

	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Bored", "Decrease");
	
	distributeExp("play");
	printStatus();
}

//feed function that prints penguin specific statements and adjusts stats, distributes experience, and prints out stats
void Penguin::feed() {
	//decrease hungriness. increase sleepiness and happiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You fed " << name << " squid!" << endl;
	}
	else if (printLine == 1) {
		cout << "You fed " << name << " krill!" << endl;
	}
	else if (printLine == 2) {
		cout << "You fed " << name << " anchovies!" << endl;
	}

	changeStatsHelper("Hungry", "Decrease");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Happy", "Increase");

	distributeExp("feed");
	printStatus();
}

//sleep function that prints penguin specific statements and adjusts stats, distributes experience, and prints out stats
void Penguin::sleep() {
	//decrease sleepiness. Increase boredom and hungriness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "Wow! " << name << " was really tired! He's knocked out!" << endl;
	}
	else if (printLine == 1) {
		cout << "You tucked in " << name << "!" << endl;
	}
	else if (printLine == 2) {
		cout << " Phew! " << name << " really put up a fight! At least they're finally asleep!" << endl;
	}

	changeStatsHelper("Sleepy", "Decrease");
	changeStatsHelper("Bored", "Increase");
	changeStatsHelper("Hungry", "Increase");

	distributeExp("sleep");
	printStatus();
}

//walk function that prints penguin specific statements and adjusts stats, distributes experience, and prints out stats
void Penguin::walk() {
	//decrease boredom. Increase hungriness, happiness, and sleepiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "It seems like " << name << " was in quite a hurry! They're all the way down the street!" << endl;
	}
	else if (printLine == 1) {
		cout << "You took a nice stroll with " << name << "!" << endl;
	}
	else if (printLine == 2) {
		cout << name << " seems to have a spunk in his step!" << endl;
	}

	changeStatsHelper("Bored", "Decrease");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Sleepy", "Increase");

	distributeExp("walk");
	printStatus();
}