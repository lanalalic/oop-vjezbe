#pragma once
#include "z2.h"
#include "Animal.h"
class Insect : public Animal {
public:
	int legs() {
		return 6;
	}
	string species() {
		return "Insect";
	}
};