#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll power(ll a, ll b, ll c) {
  ll res = 1;
  a = a % c;
  if (a == 0) return 0;

  while (b > 0) {
    if (b & 1)
      res = (res * a) % c;
    b >>= 1;
    a = (a*a) % c;
  }

  return res;
}

int main() {
  cout << power(2,5,13) << endl;
  return 0;
}
