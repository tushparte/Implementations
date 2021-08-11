#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll binPow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binPow(a, b / 2);
  if (b % 2)
    return res * res * a;
  return res * res;
}


ll binaryPow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b % 2)
      res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}

int main() {
  cout << binPow(2, 10) << endl;
  cout << binaryPow(2, 10) << endl;
  return 0;
}
