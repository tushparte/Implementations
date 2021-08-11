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

int partition(vector<int>& v, int l, int r) {
  int index = l;
  int pivot = v[r];
  for (int i = l; i < r; ++i) {
    if (v[i] <= pivot) {
      swap(v[i], v[index++]);
    }
  }
  swap(v[index], v[r]);
  return index;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v = {1, 5, 2, 6, 7, 13, 12, 0, 9};
  partition(v, 0, 8);
  for (auto x: v) cout << x << " ";
  return 0;
}
