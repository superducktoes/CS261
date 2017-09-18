/* CS261- Assignment 1 - Q.3*/
/* Name: Nick Roy
 * Date: 9/18/2017
 * Solution description: Create n number of student structs and then sort based on
 * their test scores.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sort(int* number, int n){
  /*Sort the given array number , of length n*/     
  int temp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(number[j] > number[i]) {
	temp = number[i];
	number[i] = number[j];
	number[j] = temp;
      }
    }
  }
}

int main(){
  /*Declare an integer n and assign it a value of 20.*/
  int n = 20;
  /*Allocate memory for an array of n integers using malloc.*/
  int *arr = malloc(n*sizeof(int));
  /*Fill this array with random numbers, using rand().*/
  srand(time(NULL));
  for(int i = 0; i < n; i++) {
    arr[i] = rand() % (100 + 1 - 1) + 1;
  }
  
  /*Print the contents of the array.*/
  printf("The contents of the array: ");
  for(int j = 0; j < n; j++) {
    printf(" %d ",arr[j]);
  }
  /*Pass this array along with n to the sort() function of part a.*/
  sort(arr,n);
  /*Print the contents of the array.*/    
  printf("\nThe sorted contents of the array: ");
  for(int j = 0; j < n; j++) {
    printf(" %d ",arr[j]);
  }
  printf("\n");
    return 0;
}
