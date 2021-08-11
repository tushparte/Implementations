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

class Solution {
  public:
    vector<int> v;
    int k;
    vector<vector<int>> dp;
    vector<int> prefix;

    Solution(vector<int> v, int k) {
      this->v = v;
      this->k = k;
      int n = v.size();
      dp = vector<vector<int>>(n+1, vector<int>(k+1, -1));
      prefix = vector<int>(n+1, 0);
      for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + v[i-1];
      }
    }

    int solve(int n, int k) {
      if (k == 1)
        return prefix[n];
      if (n == 1)
        return v[0];
      if (dp[n][k] != -1) return dp[n][k];
      int res = INT_MAX;
      for (int i = 1; i <= n; ++i) {
        res = min(res, max(solve(i, k-1), prefix[n]-prefix[i]));
      }
      dp[n][k] = res;
      return res;
    }

    void print() {
      for (auto x: dp) {
        for (auto y: x)
          cout << y << " ";
        cout << endl;
      }
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v{ 10, 20, 60, 50, 30, 40 };
  int k = 3;
  Solution s(v, k);
  cout << s.solve(v.size(), k);
  return 0;
}
