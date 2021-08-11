#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return gcd;
}

int modInverse(int a, int m) {
  int x, y;
  int gcd = gcdExtended(a, m, x, y);
  if (gcd != 1) return -1;
  return (x % m + m) % m; 
}

int main() {
  cout << modInverse(27, 392) << endl;
  cout << modInverse(3, 11) << endl;
  return 0;
}
