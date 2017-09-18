/* CS261- Assignment 1 - Q.5*/
/* Name: Nick Roy
 * Date: 9/17/2017
 * Solution description: Check the char's at even positions to make sure they are
 * uppercase. Check the char's at odd positions to make sure they are lowercase.
 * Update appropriately.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
  return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
  return ch-'A'+'a';
}

void sticky(char* word){
  /*Convert to sticky caps*/
  int sizeOfWord = strlen(word);
  for(int i = 0; i < sizeOfWord; i++) {
    if( i % 2 == 0) {
      if( !(*(word + i) >= 'A' && *(word + i) <= 'Z')) {
	*(word + i) = toUpperCase(*(word + i));
      }
    } else if( i % 2 == 1) {
      if(!(*(word + i) >= 'a' && *(word + i) <= 'z')) {
	*(word + i) = toLowerCase(*(word + i));
      }
    }
  }
}

int main(){
  /*Read word from the keyboard using scanf*/
  char word[100];
  printf("Enter a single word:");
  scanf("%s",word);

  /*Call sticky*/
  sticky(word);

  /*Print the new word*/
  printf("The new word is: %s\n",word);

  return 0;
}

