#pragma once 
#include "z2.h"
class Animal {
public:
	virtual int legs() = 0;
	virtual string species() = 0;
};