#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> dp) {
  for (auto x: dp) {
    for (auto y: x) cout << y << "\t";
    cout << endl;
  }
}

int knapsack(vector<int> weights, vector<int> values, int k) {
  int n = weights.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      int valWithoutCurrent = dp[i - 1][j];
      int valWithCurrent = 0;
      int weight = weights[i - 1];
      if (weight <= j) {
        int remainingCapacity = j - weight;
        valWithCurrent = values[i - 1] + dp[i - 1][remainingCapacity]; 
      }
      dp[i][j] = max(valWithCurrent, valWithoutCurrent);
    }
  }
  print(dp);
  return dp[n][k];
}

int main() {
  vector<int> values = {10, 40, 30, 50};
  vector<int> weights = {5, 4, 6, 3};
  int k = 10;
  cout << knapsack(weights, values, k) << endl;
  return 0;
}
