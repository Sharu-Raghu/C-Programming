// program written by S. Raghunath 11250416
#include <stdio.h>

int age, year, retireyear;

int main() {
	age = 64;
	year = 2013;
	retireyear = 65 - age + year;
	printf("Person will retire in %d\n", retireyear);
}
