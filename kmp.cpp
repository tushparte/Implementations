#include <bits/stdc++.h>

using namespace std;

vector<int> KMP(string needle) {
  int n = needle.size();
  vector<int> dp(n, 0);
  for (int i = 1, len = 0; i < n;) {
    if (needle[i] == needle[len]) {
      dp[i++] = ++len;
    } else if (len) {
      len = dp[len - 1];
    } else {
      dp[i++] = 0;
    }
  }
  return dp;
}

int main() {
  string s;
  cin >> s;
  auto v = KMP(s);
  for (auto c: s)
    cout << c << "\t";
  cout << endl;
  for (auto x: v)
    cout << x << "\t";
  return 0;
}
