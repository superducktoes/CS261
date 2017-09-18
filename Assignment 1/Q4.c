/* CS261- Assignment 1 - Q.4*/
/* Name: Nick Roy
 * Date: 9/18/2017
 * Solution description: Combine the first and third programs to create student
 * structs with random data and then sort the students. When sorting the id's also
 * need to be considered and moved appropriately.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
  int id;
  int score;
};

void sort(struct student* students, int n){
  /*Sort the n students based on their score*/     
  int tempScore, tempStudent;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if((students + i)->score < (students + j)->score) {
	tempScore = (students + i)->score;
	tempStudent = (students + i)->id;
	(students + i)->score = (students + j)->score;
	(students + i)->id = (students + j)->id;
	(students + j)->score = tempScore;
	(students + j)->id = tempStudent;
      }
    }
  }
}

int main(){
  /*Declare an integer n and assign it a value.*/
  int n = 10;
  
  /*Allocate memory for n students using malloc.*/
  struct student *s = malloc(sizeof(struct student)*n);
  
  /*Generate random and unique IDs and random scores for the n students, using rand().*/
  srand(time(NULL));
  printf("The initial list of students and scores:\n");
  for(int i = 0; i < n; i++) {
    (s + i)->id = rand() % (25 + 1 - 1) + 1;
    (s + i)->score = rand() % (100 + 1 - 1) + 1;
  }
  
  /*Print the contents of the array of n students.*/
  for(int j = 0; j < n; j++) {
    printf("Student: %d\t Score: %d \n", (s + j)->id, (s + j)->score);
  }
  
  /*Pass this array along with n to the sort() function*/
  sort(s, n);
  
  /*Print the contents of the array of n students.*/
  printf("The sorted list of students and scores:\n");
  for(int k = 0; k < n; k++) {
    printf("Student: %d\t Score: %d \n", (s + k)->id, (s + k)->score);
  }
  
  return 0;
}
