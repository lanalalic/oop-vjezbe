#pragma once
#include "z2.h"
#include "Spider.h"
class DaddyLongLegs : public Spider {
public:
	int legs() {
		return 8;
	}
	string species() {
		return "Daddy long legs";
	}
};