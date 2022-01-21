#pragma once
#include "z2.h"
#include "Spider.h"
class Tarantula : public Spider {
public:
	int legs() {
		return 8;
	}
	string species() {
		return "Tarantula";
	}
};