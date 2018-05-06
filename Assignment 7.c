// program written by S. Raghunath 11250416

#include <stdio.h>
#include <string.h>

int gaps, length, width, i, extras, share, odds, n;

char line[100];

int main() {
	gaps = 0;
	printf("Please enter the column width: ");
	scanf("%d", &width);
	fflush (stdin);
	printf("Please enter the line of text: ");
	gets (line);
	length = strlen (line);
	printf("\n");
	while (length > width) {
		printf("Problem! Enter a shorter line of text: \n");
		gets (line);
		length = strlen (line);
	}
	for (i = 0; i < length; i++) {
		if (line[i] == ' ') {
			gaps++;
		}
	}
	odds = width - length;
	share = odds / gaps;
	for (i = 0; i < length; i++) {
		printf("%c", line[i]);
		if (line[i] == ' ') {
			for (n = 0; n <= share; n++) {
				printf(" ");
			}
			if (extras != 0) {
				printf(" ");
				extras -= 1;
			}
		}
	}
}
