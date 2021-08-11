#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5+10;
ll bit[N];

void update(ll i, ll x) {
  for (; i<N; i+=(i&-i))
    bit[i]+=x;
}

ll sum(ll i) {
  ll res = 0;
  for (; i>0; i-=(i&-i))
    res += bit[i];
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  ll a[n+10];
  map<ll, ll> m;
  for (ll i=1; i<=n; ++i) {
    cin >> a[i];
    m[a[i]];
  }
  ll ptr=1;
  for (auto &[x,y]: m)
    y=ptr++;
  for (ll i=1; i<=n; ++i)
    a[i]=m[a[i]];
  ll res = 0;
  for (ll i=1; i<=n; ++i) {
    res += (sum(N-5)-sum(a[i]));
    update(a[i], 1);
  }
  cout << res << endl;
  return 0;
}
