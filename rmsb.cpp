#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  int x = n & -n;
  int y = (n & (n - 1)) ^ n;
  int z = n & ~(n-1);
  cout << x << " " << y << " " << z << endl;
  return 0;
}
