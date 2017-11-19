#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
  // FIXME: implement
  char* word = nextWord(file);
  while(word) {
    hashMapPut(map,word,1);
    free(word);
    word = nextWord(file);
  }

}

/* Implementation found here: https://rosettacode.org/wiki/Levenshtein_distance#C */

int levenshtein(const char *s, const char *t)
{
  int ls = strlen(s), lt = strlen(t);
  int d[ls + 1][lt + 1];
  
  for (int i = 0; i <= ls; i++)
    for (int j = 0; j <= lt; j++)
      d[i][j] = -1;
  
  int dist(int i, int j) {
    if (d[i][j] >= 0) return d[i][j];
    
    int x;
    if (i == ls)
      x = lt - j;
    else if (j == lt)
      x = ls - i;
    else if (s[i] == t[j])
      x = dist(i + 1, j + 1);
    else {
      x = dist(i + 1, j + 1);
      
      int y;
      if ((y = dist(i, j + 1)) < x) x = y;
      if ((y = dist(i + 1, j)) < x) x = y;
      x++;
    }
    return d[i][j] = x;
  }
  return dist(0, 0);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (quit != 1)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
	if (strcmp(inputBuffer, "quit") == 0) {
	  quit = 1;
	}
	

	if(hashMapContainsKey(map,inputBuffer)) {
	  printf("%s is in the dictionary!\n", inputBuffer);
	} else {
	  int i;
	  int stopSuggestions = 0;
	  printf("%s is not in the dictionary.\n", inputBuffer);
	  printf("Maybe you meant one of the following words:\n");
	  for(i = 0; i < hashMapCapacity(map); i++) {
	    struct HashLink* current = map->table[i];
	    if(current != NULL) {
	      
	      while(current != NULL) {
		int score;
		score = levenshtein(inputBuffer, current->key);
		if(score < 2) {
		  printf("%s\n", current->key);
		  stopSuggestions = stopSuggestions + 1;
		}
		if(stopSuggestions < 5) {
		  current = current->next;
		} else {
		  current = NULL;
		}
	      }
	    }
	  }
	  if(stopSuggestions == 0) {
	    printf("No Matches Found\n");
	  }
	}	  
    }
    hashMapDelete(map);
    printf("Thanks for looking up some words!\n");
    return 0;
}
