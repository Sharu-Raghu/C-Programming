// program written by S. Raghunath 11250416

#include <stdio.h>

char *stringcopy (char *destination, char *source);
int stringlength (char *str);
char *stringcat (char *destination, char *source);
int stringcompare (char *str1, char* str2);

int main() {
	char s[80], t[80];
	char choice, result;
	printf("Please select one from the following options:\n\n");
	printf("A. Test the stringcopy function\n");
	printf("B. Test the stringlength function\n");
	printf("C. Test the stringcat function\n");
	printf("D. Test the stringcompare function\n");
	printf("Q. Quit\n\n");
	choice = getchar();
	getchar();
	printf("\n");
	if (choice == 'A') {
		printf("A. Test the stringcopy function\n\n");
		printf("Please type in string to copy:\n");
		gets(s);
		printf("\nThe copied string is: \n%s\n", stringcopy(t, s));
	}
	if (choice == 'B') {
		printf("B. Test the stringlength function\n\n");
		printf("Please type in a string:\n");
		gets(s);
		printf("\nThe length of the string is %u characters\n", stringlength(s));
	}
	if (choice == 'C') {
		printf("C. Test the stringcat function\n\n");
		printf("Please type in a string:\n");
		gets(s);
		printf("\nPlease type in a string to add to it:\n");
		gets(t);
		printf("\nThe concatenated string is: \n%s\n", stringcat(s, t));
	}
	if (choice == 'D') {
		printf("D. Test the stringcompare function\n\n");
		printf("Please type in a string:\n");
		gets(s);
		printf("\nPlease type in another string to compare:\n");
		gets(t);
		result = stringcompare(s, t);
		if (result == 0) {
			printf("\nThe strings are equal\n");
		} else {
			printf("\nThe strings are NOT equal\n");
		}
	}
	if (choice == 'Q') {
		printf("Q. Quit\n\n");
	}
}

char *stringcopy (char *destination, char *source)
{
	char *dest = destination; 
   while((*dest++ = *source++) != '\0');
   return destination;
}

int stringlength (char *str) {
   char sz = 0;
   while(*str++ != '\0') sz++;
   return sz; 
}

char *stringcat (char *destination, char *source) {
   char *dest = destination; 
   while(*++dest != '\0');
   while((*dest++ = *source++) != '\0');
   return destination;
}

int stringcompare (char *str1, char* str2) {
   for( ; *str1 == *str2; str1++, str2++) {
      if (*str1 == '\0') return 0;
   }
   return *str1 - *str2;      
}
