#include <stdio.h>

int recursiveFactorial(int n) {
  if (n == 1) return 1;
  else return recursiveFactorial(n - 1) * n;
}

int iterativeFactorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}


int main(int argsc, char **argsv) {
  printf("The factorial of 5 using recursion is: %d\n", recursiveFactorial(5));
  printf("The factorial of 5 using iteration is: %d\n", iterativeFactorial(5));
  return 0;
}
