#pragma once
#include "z2.h"
#include "Bird.h"
class Seagull : public Bird {
public:
	int legs() {
		return 2;
	}
	string species() {
		return "Seagull";
	}
};