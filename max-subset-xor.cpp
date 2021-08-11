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

int maxSubseXOR(vector<int> v) {
  int index = 0;
  for (int i = 31; i >= 0; --i) {
    int maxIndex = index;
    int maxElement = INT_MIN;
    for (int j = index; j < v.size(); ++j) {
      if (v[j] & (1 << i) and v[j] > maxElement) {
        maxElement = v[j];
        maxIndex = j;
      }
    }
    // if theres no number with ith set bit then move on to lower bit
    if (maxElement == INT_MIN)
      continue;
    swap(v[index], v[maxIndex]);
    maxIndex = index;
    // if there are multiple numbers with ith set bit then xor them with maxElement to unset that bit
    for (int j = 0; j < v.size(); ++j) {
      if (j == maxIndex) continue;
      if (v[j] & (1 << i))
        v[j] ^= maxElement;
    }
  }

  // result is xor of all numbers
  int res = 0;
  for (auto x: v)
    res ^= x;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v{9, 8, 5};
  cout << maxSubseXOR(v) << endl;
  return 0;
}
