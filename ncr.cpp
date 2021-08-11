#include <bits/stdc++.h>

using namespace std;

/*
 * C(n, r) = C(n-1, r-1) + C(n-1, r)
 * C(n, 0) = C(n, n) = 1 
 * So
 * C(n, r) % p = [C(n-1, r-1)%p + C(n-1, r)%p] % p
 * C(n, 0) = C(n, n) = 1
 * */

// O(n * r)
int nCrModp(int n, int r, int p) {
  if (r > n - r) r = n - r;
  int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = min(i, r); j > 0; --j)
      C[j] = (C[j] + C[j - 1]) % p;
  return C[r];
}

// O(k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k) {
  unsigned long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

int main() {
  cout << nCrModp(10, 2, 13) << endl;
  return 0;
}
