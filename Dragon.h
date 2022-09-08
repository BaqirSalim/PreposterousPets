#pragma once
#include "Pet.h"

class Dragon : public Pet
{
public:
	Dragon();
	void play();
	void feed();
	void sleep();
	void walk();
};