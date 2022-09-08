#pragma once

#include "Pet.h"

class Penguin : public Pet
{
public:
	Penguin();
	void play();
	void feed();
	void sleep();
	void walk();
};