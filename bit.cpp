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

class BIT {
  public:
  vector<int> bit;
  int n;

  BIT (int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  BIT (vector<int> a) : BIT(a.size()) {
    for (int i = 0; i < n; ++i) {
      add(i, a[i]);
    }
  }

  int sum (int r) {
    int res = 0;
    for (; r >=0; r = (r & (r + 1)) - 1) {
      res += bit[r];
    }
    return res;
  }

  int sum (int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add (int index, int delta) {
    for (; index < n; index = index | (index + 1)) {
      bit[index] += delta;
    }
  }
};

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BIT b(v);
  cout << b.sum(0, 9) << endl;
  b.add(0, 1);
  cout << b.sum(0, 9) << endl;
  return 0;
}
