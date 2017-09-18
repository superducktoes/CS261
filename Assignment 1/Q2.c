/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
  /*Set a to double its original value*/
  *a = *a * 2;
  /*Set b to half its original value*/
  *b = .5*(*b);
  /*Assign a+b to c*/
  c = *a + *b;
  /*Return c*/
  return c;
}

int main(){
  /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
  int x = 5;
  int y = 6;
  int z = 7;
  
  /*Print the values of x, y and z*/
  printf("The value of x is: %d\n", x);
  printf("The value of y is: %d\n", y);
  printf("The value of z is: %d\n", z);
  
  /*Call foo() appropriately, passing x,y,z as parameters*/
  int fooVar = foo(&x, &y, z);
  /*Print the value returned by foo*/
  printf("The value returned by foo is: %d\n", fooVar);

  /*Print the values of x, y and z again*/
  printf("The value of x is: %d\n", x);
  printf("The value of y is: %d\n", y);
  printf("The value of z is: %d\n", z);
  
  /*Is the return value different than the value of z?  Why?*/

  /*
   * The return value is different from the value of z. 
   * This is because x and y were passed into foo()
   * by reference while z is passed by value. 
   * Due to the scope of the variable foo() is not able to 
   * modify z outside of the function unline x and y.
   *
   */
  
  return 0;
}
    
    
