// program written by S. Raghunath 11250416

#include <stdio.h>

int n, r, ncr;

int factorial(int x);

int main() {
	printf("Please enter in two numbers, eg 6 2 and press enter: ");
	scanf("%d %d", &n, &r);
	if ((n <= 12) && (r < n) && (n > 0) && (r > 0)) {
		ncr = factorial(n) / (factorial(r) * factorial(n-r));
		printf("The NCR of %d(n) and %d(r) is: %d\n", n, r, ncr);
	}
}

int factorial(int x) {
	int fact;
	fact = 1;
	while (x != 0) {
		fact = fact * x;
		x--;
	}
	return fact;
}
