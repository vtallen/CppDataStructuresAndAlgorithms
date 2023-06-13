#include <stdio.h>

int recursiveSum(int n) {
  if (n == 0) return 0;
  else return recursiveSum(n - 1) + n;
}

int iterativeSum(int n) {
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result += i; 
  }
  return result;
}

int formulaSum(int n) {
  return n * (n + 1) / 2;
}

int main(int argsc, char** argsv) {
  printf("Sum of natural numbers up to 10 using recursion: %d\n", recursiveSum(10));
  printf("Sum of natural numbers up to 10 using a loop: %d\n", iterativeSum(10));
  printf("Sum of natural numbers up to 10 using a formula: %d\n", formulaSum(10));

}
