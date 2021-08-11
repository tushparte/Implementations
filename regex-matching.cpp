#include <bits/stdc++.h>

using namespace std;

#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define INF 0x3f3f3f3f
#define f1(i, n) for (int i = 0; i < n; ++i)
#define f2(i, n) for (int i = 1; i < n; ++i)
#define f3(i, start, end) for (int i = start; i < end; ++i)
#define ll long long
typedef pair<int, int> iPair;
const double epsilon = 1e-7;

bool regexMatch(string s, string p) {
  int m = s.size(), n = p.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, false));
  dp[0][0] = true;
  for (int i=1; i<=n; ++i) {
    if (p[i-1] == '*' and dp[0][i-2])
      dp[0][i] = true;
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j-1] == '*') {
        dp[i][j] = dp[i][j-2] or (dp[i-1][j] and (s[i-1] == p[j-2] or p[j-2] == '.'));
      } else if (s[i-1] == p[j-1] or p[j-1] == '.') {
        dp[i][j] = dp[i-1][j-1];
      }
    }
  }

  return dp[m][n];
}

bool wildCardMatch(string s, string p) {
  int m = s.size(), n = p.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, false));
  // empty string and pattern are equal
  dp[0][0] = true;
  for (int i=1; i<=n; ++i) {
    if (p[i-1] == '*')
      dp[0][i] = dp[0][i-1];
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j-1] == '*') {
        dp[i][j] = dp[i][j-2] or (dp[i-1][j] and (s[i-1] == p[j-2] or p[j-2] == '.'));
      } else if (s[i-1] == p[j-1] or p[j-1] == '?') {
        dp[i][j] = dp[i-1][j-1];
      }
    }
  }

  return dp[m][n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s = "aab";
  string p = "c*a*b";
  cout << regexMatch(s, p) << endl;
  return 0;
}
