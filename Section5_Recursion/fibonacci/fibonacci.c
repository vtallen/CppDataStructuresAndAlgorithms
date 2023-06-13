#include <stdio.h>

int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n - 2) + fib(n - 1);
}

int fibIter(int n) {
  int first = 0, second = 1, result = 0;
  if (n <= 1) return n;

  for (int i = 2; i <= n; ++i) {
    result = first + second;
    first = second;
    second = result;
  }

  return result;
}


int fibArr(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  static int results[100];
  if (results[n] != 0) return results[n];
  
  results[n] = fibArr(n - 2) + fibArr(n - 1);
  return results[n];
}

int main() {
  printf("7th digit of the Fibonacci Series using recursion: %d\n", fib(7));
  printf("7th digit of the Fibonacci Series using a loop: %d\n", fibIter(7));
  printf("7th digit of the Fibonacci Series using a more efficent recursive algo: %d\n", fibArr(7));
  return 0;
}
