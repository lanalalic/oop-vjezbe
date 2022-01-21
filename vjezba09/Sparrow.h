#pragma once
#include "z2.h"
#include "Bird.h"

class Sparrow : public Bird {
public:
	int legs() {
		return 2;
	}
	string species() {
		return "Sparrow";
	}
};