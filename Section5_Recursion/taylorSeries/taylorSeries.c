#include <stdio.h>

double e(int x, int n) {
  static double p=1, f=1;
  double r;

  if (n == 0) return 1;

  r = e(x, n-1);
  p = p * x;
  f = f * n;
  return r + p / f;
}

double eHornersRecursive(int x, int n) {
  static double s;
  if (n == 0) return s;

  s = 1 + (double)x/n * s;
  return eHornersRecursive(x, n - 1); 
}

double eHornersIterative(int x, int n) {
  double s = 1;
  int i;
  double pow = 1;
  double fac = 1;

  for (i = 1; i <= n; ++i) {
    pow *= x;
    fac *= i;
    s += pow/fac;
  }

  return s;
}


int main() {
  printf("e^1 to 10 digits using recursion is: %lf\n", e(1, 10));
  printf("e^1 to 10 digits using Horner's rule and iteration is: %lf\n", eHornersIterative(1, 10));
  printf("e^1 to 10 digits using Horner's rule and recursion is: %lf\n", eHornersRecursive(1, 10));
  return 0;
}
