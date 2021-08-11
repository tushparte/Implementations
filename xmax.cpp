// https://stackoverflow.com/questions/27470592/maximum-xor-among-all-subsets-of-an-array#
#include <bits/stdc++.h>

using namespace std;

#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define INF 0x3f3f3f3f
#define f1(i, n) for (int i = 0; i < n; ++i)
#define f2(i, n) for (int i = 1; i < n; ++i)
#define f3(i, start, end) for (int i = start; i < end; ++i)
#define ll long long
#define ull unsigned long long
typedef pair<int, int> iPair;
const double epsilon = 1e-7;
ull n;
vector<ull> arr;

ull check_bit(ull N, int pos) {
  return (N & (1ULL << pos));
}

ull gaussian_elemination() {
  int ind = 0;
  for (int bit=log2(arr[0]); bit >= 0; --bit) {
    int x = ind;
    while (x < n and check_bit(arr[x], bit) == 0) x++;
    if (x == n) continue;

    swap(arr[ind], arr[x]);

    for (int j = 0; j < n; ++j) {
      if (j != ind and check_bit(arr[j], bit))
          arr[j] ^= arr[ind];
    }
    ind++;
  }
  ull res = arr[0];
  for (int i = 1; i < n ; ++i)
    res = max(res, res^arr[i]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  arr = vector<ull>(n);
  f1 (i, n) cin >> arr[i];
  sort(arr.rbegin(), arr.rend());
  cout << gaussian_elemination() << endl;
  return 0;
}
