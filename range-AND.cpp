#include <bits/stdc++.h>

using namespace std;

/*
  src: https://www.geeksforgeeks.org/queries-for-bitwise-and-in-the-index-range-l-r-of-the-given-array/
 */

#define bitscount 32
#define MAX 100000

int prefix_count[bitscount][MAX];

void findPrefixCount(vector<int> v) {
  int n = v.size();
  for (int i = 0; i < bitscount; ++i) {
    prefix_count[i][0] = ((v[0] >> i) & 1);
    for (int j = 1; j < n; ++j) {
      prefix_count[i][j] = ((v[j] >> i) & 1);
      prefix_count[i][j] += prefix_count[i][j - 1];
    }
  }
}

int rangeAnd(int l, int r) {
  int res = 0;
  for (int i = 0; i < bitscount; ++i) {
    int x = prefix_count[i][r];
    if (l > 0) x -= prefix_count[i][l - 1];
    if (x == r - l + 1)
      res = (res | (1 << i));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v = {7, 5, 3, 5, 2, 3};
  findPrefixCount(v);
  cout << rangeAnd(1, 3) << endl;
  cout << rangeAnd(4, 5) << endl;
  return 0;
}
