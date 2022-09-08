#pragma once

#ifndef PETH
#define PETH

#include <string>
#include <iostream>

using namespace std;

class Pet {

public:
	Pet();
	int generateRandom();
	void distributeExp(string);
	void levelUp();
	virtual void play() = 0;
	virtual void feed() = 0;
	virtual void sleep() = 0;
	virtual void walk() = 0;
	string getName();
	void printStatus();
	void setName(string);
	bool save(string);
	bool load(string);
	void nextHour();
	
protected:
	struct rate {
		double increase;
		double decrease;
	};
	string name;
	int level;
	double exp;
	double expThreshold;
	double percentHappy;
	double percentHungry;
	double percentSleepy;
	double percentBored;
	rate happyRate;
	rate hungryRate;
	rate sleepyRate;
	rate boredRate;
	void changeStatsHelper(string, string);
};

#endif // !PETH
