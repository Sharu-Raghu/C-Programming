// program written by S. Raghunath 11250416

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *document;

void convert(char s[20], char t[20]);
void removeline(char s[20], char t[20]);

char line1[100], line2[100];
char filename[100];
char word[20], word1[20], word2[20], copy_word1[20], copy_word2[20];

int word_count1, word_count2, line_counter;
     
int main() {
   int i, j;
	printf("Enter the first word: ");
   gets(word1);
   convert(word1, copy_word1);
   printf("\nEnter the second word: ");
   gets(word2);
   convert(word2, copy_word2);
   printf("\nEnter the name of the text file: ");
   gets(filename);
   document = fopen(filename, "r");
	if (document == NULL) {
		printf("\nError! Cannot open %s\n", filename);
		exit(99);
	}
   word_count1 = word_count2 = line_counter = 0;
   while (!feof (document)) {
      line_counter++;
      fgets(line1, 100, document);
      removeline(line1, line2);
      i = j = 0;
      while (line1[i] != '\0') {
        if (line1[i] != ' ' && line1[i] != '.' && line1[i] != '\n') {
           word[j] = tolower(line1[i]);
           j++;
        } else {
			  word[j] = '\0';
           j = 0;
           if (!strcmp (word, copy_word1)) { 
              word_count1++;
              if (word_count1 == 1) {
                 printf("\nThe word \'%s\' first appears in line %d which is:\n\n%s\n", word1, line_counter, line2); 
              }
           }
           else if (!strcmp(word, copy_word2)) {
              word_count2++;
              if (word_count2 == 1) {
                 printf("\nThe word \'%s\' first appears in line %d which is:\n\n%s\n", word2, line_counter, line2); 
              }
           }
        }
        i++;
      }      
   }
   if (word_count1 > 0) {
      printf("\nThe word \'%s\' appears %d time(s) in the file.\n", word1, word_count1);
   } else {
      printf("\nThe word \'%s\' does not appear in the file.\n", word1);
   }
   if (word_count2 > 0) {
      printf("\nThe word \'%s\' appears %d time(s) in the file.\n", word2, word_count2);
   } else {
      printf("\nThe word \'%s\' does not appear in the file.\n", word2);
   }
   fclose(document);
}

void convert(char a[20], char b[20]) { 
	int i;
	i = 0;
	while (a[i] != '\0') {
      b[i] = tolower(a[i]);
      i++;
   }
	b[i] = '\0';
}

void removeline(char a[20], char b[20]) { 
	int i;
	i = 0;
	while (a[i] != '\n') {
		b[i] = a[i];
		i++;
   }
	b[i] = '\0';
}
