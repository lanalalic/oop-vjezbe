#pragma once
#include "z2.h"
#include "Insect.h"
class StinkBug : public Insect {
public:
	int legs() {
		return 6;
	}
	string species() {
		return "Stink bug ewww";
	}
};