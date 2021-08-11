#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int w, int n) {
  if (n == 0 or w == 0)
    return 0;
  if (weights[n-1] > w)
    return knapsack(weights, values, w, n-1);
  return max (
      values[n-1] + knapsack(weights, values, w - weights[n-1], n-1),
      knapsack(weights, values, w, n-1)
      );
}

int main() {
  vector<int> values{60,100,120};
  vector<int> weights{10,20,30};
  cout << knapsack(weights, values, 50, 3) << endl;
  return 0;
}
