#include <stdio.h>

int recursivePower(int num, int power) {
  if (power == 0) return 1;
  return recursivePower(num, power - 1) * num; 
}

int efficiantPower(int num, int power) {
  if (power == 0) return 1;
  if (power % 2 == 0) return efficiantPower(num * num, power / 2);
  else return num * efficiantPower(num * num, (power - 1) / 2); 
}

int iterativePower(int num, int power) {
  int result = 1;
  for (int i = 1; i <= power; ++i) {
    result *= num;
  }
  return result; 
}

int main() {
  printf("3^3 using recursion is: %d\n", recursivePower(3, 3));
  printf("3^3 using more efficiant recursion is: %d\n", efficiantPower(3, 3));
  printf("3^3 using a loop is: %d\n", iterativePower(3, 3));
  return 0;
}
