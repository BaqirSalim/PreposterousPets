#include "Triceratops.h"

//constructor that assigns all variables triceratops specific stats
Triceratops::Triceratops() {
	percentHappy = 70.0;
	percentHungry = 70.0;
	percentSleepy = 60.0;
	percentBored = 10.0;
	happyRate.increase = .12;
	happyRate.decrease = .02;
	hungryRate.increase = .15;
	hungryRate.decrease = .4;
	sleepyRate.increase = .2;
	sleepyRate.decrease = .45;
	boredRate.increase = .2;
	boredRate.decrease = .1;
}

//play function that prints triceratops specific statements and adjusts stats, distributes experience, and prints out stats
void Triceratops::play() {
	//increase, happiness, hungriness, and sleepiness. decrease boredom
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You played fetch with " << name << "!" << endl;
	}
	else if (printLine == 1) {
		cout << "You took " << name << " to play with your friendly neighborhood T-Rex!" << endl;
	}
	else if (printLine == 2) {
		cout << "You took " << name << " to the Natural Science Museum! Hey why are there other triceratops in there?" << endl;
	}

	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Bored", "Decrease");

	distributeExp("play");
	printStatus();
}

//feed function that prints triceratops specific statements and adjusts stats, distributes experience, and prints out stats
void Triceratops::feed() {
	//decrease hungriness. increase sleepiness and happiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "You fed " << name << " a whole tree!" << endl;
	}
	else if (printLine == 1) {
		cout << "You fed " << name << " a whole lot of lettuce!" << endl;
	}
	else if (printLine == 2) {
		cout << "You fed " << name << " a huge salad!" << endl;
	}

	changeStatsHelper("Hungry", "Decrease");
	changeStatsHelper("Sleepy", "Increase");
	changeStatsHelper("Happy", "Increase");

	distributeExp("feed");
	printStatus();
}

//sleep function that prints triceratops specific statements and adjusts stats, distributes experience, and prints out stats
void Triceratops::sleep() {
	//decrease sleepiness. Increase boredom and hungriness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << "Wow! " << name << " is sleeping as still as a rock!" << endl;
	}
	else if (printLine == 1) {
		cout << name << " is rocking back and forth in their sleep! Must be one crazy dream!" << endl;
	}
	else if (printLine == 2) {
		cout << " Youch! One of " << name << "'s horns poked you while you were tucking them in! And now they're giggling too much to sleep. Good luck!" << endl;
	}

	changeStatsHelper("Sleepy", "Decrease");
	changeStatsHelper("Bored", "Increase");
	changeStatsHelper("Hungry", "Increase");

	distributeExp("sleep");
	printStatus();
}

//walk function that prints triceratops specific statements and adjusts stats, distributes experience, and prints out stats
void Triceratops::walk() {
	//decrease boredom. Increase hungriness, happiness, and sleepiness.
	int printLine = generateRandom();
	if (printLine == 0) {
		cout << name << " seems to like walking next to you!" << endl;
	}
	else if (printLine == 1) {
		cout << "Woah! " << name << " ran into a tree for a little snack!" << endl;
	}
	else if (printLine == 2) {
		cout << name << "'s footsteps are shaking the whole neighborhood!" << endl;
	}

	changeStatsHelper("Bored", "Decrease");
	changeStatsHelper("Hungry", "Increase");
	changeStatsHelper("Happy", "Increase");
	changeStatsHelper("Sleepy", "Increase");

	distributeExp("walk");
	printStatus();
}