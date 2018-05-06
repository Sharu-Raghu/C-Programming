// program written by S. Raghunath 11250416

#include <stdio.h>
#include <string.h>

struct contactlist {
	char name[50];
	char telephone[50];
};

contactlist getdetails(char line[]);
void alphabetical_sorting(contactlist phonelist[], int start, int n);

char choice;

int main() {
	contactlist phonelist[100];
	int i, count, found;
	char line[200];
	char search[200];
	FILE *f;
	f = fopen("C:\\Users\\Andrew\\Desktop\\numbers.txt", "r");
	i = 0;
	while (fgets(line, 200, f) != NULL) {
		phonelist[i] = getdetails(line);
		i++;
	}
	count = i;
	fclose(f);
	printf("A. Search for a name\n\n");
	printf("B. Display all names\n\n");
	printf("Q. Quit\n\n");
	printf("Please type in your choice: ");
	choice = getchar();
	getchar();
	printf("\n");
	alphabetical_sorting(phonelist, 0, count);
	if (choice == 'A') {
		printf("Type in the name of the contact: ");
		gets(search);
		found = 0;
		for (i = 0; i < count; i++) {
			if (!strcmp(phonelist[i].name, search)) {
				printf("\n");
				printf("The phone number of %s is %s", phonelist[i].name, phonelist[i].telephone);
				found = 1;
			}
		}
		if (found == 0) {
			printf("\n");
			printf("Error! Sorry we are unable to find that person in the Contact List\n");
		}
	}
	if (choice == 'B') {
		for (i = 0; i < count; i++) {
			printf("%s\n", phonelist[i].name);
		}
	}
	if (choice == 'Q') {
		printf("Quit\n");
	}
}

contactlist getdetails(char line[]) {
	contactlist person;
	int i = 0, j = 0;
	while (line[i] != ';') {
		person.name[i] = line[i];
		i++;
	}
	person.name[i] = '\0';
	i++;
	while (line[i] != '\n') {
		person.telephone[j] = line[i];
		i++;
		j++;
	}
	person.telephone[j] = '\0';
	return person;
}

void alphabetical_sorting(contactlist phonelist[], int start, int n) {
	int i, j;
	contactlist temp;
	for (i = 1 + start; i < start + n; i++) {
		for (j = start + n - 1; j >= i; j--) {
			if (strcmp(phonelist[j - 1].name, phonelist[j].name) > 0) {
				temp = phonelist[j - 1];
				phonelist[j - 1] = phonelist[j];
				phonelist[j] = temp;
			}
		}
	}
}
