#pragma once
#include "z2.h"
#include "Animal.h"
class Bird : public Animal {
public:
	int legs() {
		return 2;
	}
	string species() {
		return "Bird";
	}
};
