#include <bits/stdc++.h>

using namespace std;

double nthRoot(int n, int a) {
  double x;
  double pre = rand() % 10;
  double eps = 1e-3;
  double dif = INT_MAX;
  while (dif > eps) {
    x = ((n - 1) * pre + (double) a / pow (pre, n - 1)) / n;
    dif = abs(x - pre);
    pre = x;
  }
  return x;
}

int main() {
  cout << nthRoot(2, 50) << endl;
  return 0;
}
