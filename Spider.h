#pragma once
#include "z2.h"
#include "Animal.h"
class Spider : public Animal {
public:
	int legs() {
		return 8;
	}
	string species() {
		return "Spider";
	}
};