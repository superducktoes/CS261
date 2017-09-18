/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
struct student{
  int id;
  int score;
};

struct student* allocate(){
  /*Allocate memory for ten students*/
  struct student *s = malloc(sizeof(struct student)*10);
  /*return the pointer*/
  return s;
}

void generate(struct student* students){
  /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    (students + i)->id = rand() % (10 + 1 - 1) + 1;
    (students + i)->score = rand() % (100 + 1 - 1) + 1;
  }
}

void output(struct student* students){
  /*Output information about the ten students in the format:
    ID1 Score1
    ID2 score2
    ID3 score3
    ...
    ID10 score10*/
  for(int i = 0; i < 10; i++) {
    printf("%d %d\n",(students+i)->id, (students+i)->score);
  }
}

void summary(struct student* students){
  /*Compute and print the minimum, maximum and average scores of the ten students*/
  int maximumScore = 0;
  int minimumScore = 100;
  int average = 0;
  float totalAverage = 0.00;
  
  for(int i = 0; i < 10; i++) {
    average = average + (students+i)->score;

    if((students+i)->score > maximumScore) {
      maximumScore = (students+i)->score;
    }
    
    if((students+i)->score < minimumScore) {
      minimumScore = (students+i)->score;
    }
  }

  totalAverage = average / 10.00;
  
  printf("The max score is: %d\n", maximumScore);
  printf("The min score is: %d\n", minimumScore);
  printf("The average score is: %3.2f\n", totalAverage);
  
}
void deallocate(struct student* stud){
  /*Deallocate memory from stud*/
  free(stud);
  stud = 0;
}

int main(){
  struct student* stud = NULL;
  
  /*call allocate*/
  stud = allocate(stud);
  /*call generate*/
  generate(stud);
  /*call output*/
  output(stud);
  /*call summary*/
  summary(stud);
  /*call deallocate*/
  deallocate(stud);
  
  return 0;
}
