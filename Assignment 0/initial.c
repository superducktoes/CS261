#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  float a = 5.0;
  float b = 5.0;
  float c = 5.0;
  float s, total;

  s = (a + b + c)/2;
  total = sqrt((s*(s-a))*(s-b)*(s-c));
  printf("%3.3f",total);

  return 0;
}
