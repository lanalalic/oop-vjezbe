#pragma once
#include "z2.h"
#include "Insect.h"
class Cockroach : public Insect {
public:
	int legs() {
		return 6;
	}
	string species() {
		return "Cockroach";
	}
};