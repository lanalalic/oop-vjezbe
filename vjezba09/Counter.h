#pragma once
#include "z2.h"
#include "Animal.h"
class Counter {
public:
	int legsSum = 0;
	void getAnimal(Animal& animal) {
		cout << "Animal added : " << animal.species() << endl;
		legsSum = legsSum + animal.legs();
	}
	void sumOfLegs() {
		cout << "Sum of all legs : " << legsSum;
	}
};