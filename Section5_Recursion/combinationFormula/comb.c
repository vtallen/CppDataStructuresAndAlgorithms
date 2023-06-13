#include <stdio.h>

int fact(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }

  return result;
}

int combForm(int n, int r) {
  int fact1, fact2, fact3;

  fact1 = fact(n);
  fact2 = fact(r);
  fact3 = fact(n - r);

  return fact1 / (fact2 * fact3);
}

int comb(int n, int r) {
  if (r == 0 || n == r) return 1;
  return comb(n-1, r-1) + comb(n-1, r);
}

int main() {
  printf("nCr of 4, 2 is: %d\n", comb(4, 2));
  return 0;
}
