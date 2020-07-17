#include <bits/stdc++.h>

using namespace std;

double squareRoot(double n) {
  double pre = rand() % 10;
  double eps = 1e-3;
  double dif = INT_MAX;
  double x;
  while (dif > eps) {
    x = (double)(pre * pre + n) / (2 * pre);
    dif = abs (x - pre);
    pre = x;
  }
  return x;
}

int main() {
  cout << squareRoot(0.5) << endl;
}
