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

void func(string s, int k) {
  int start = 0;
  int len = 0;
  int i, j;
  unordered_map<char, int> st;
  for (i = 0, j = 0; j < s.size(); ++j) {
    while (i < j and st.size() > k) {
      if (--st[s[i]] == 0)
        st.erase(s[i]);
      i++;
    }
    if (j - i + 1 > len) {
      len = j - i + 1;
      start = i;
    }
    // cout << i << " " << j << " " << st.size() << endl;
    st[s[j]]++;
  }
  cout << s.substr(i, len) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  func("aabacbebebe", 3);
  return 0;
}
