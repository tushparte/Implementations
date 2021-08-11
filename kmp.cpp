#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();
    if (!n) return 0;
    vector<int> dp = KMP(needle);

    for (int i = 0, j = 0; i < m;) {
      if (haystack[i] == needle[j]) {
        i++;
        j++;
      }
      if (j == n) {
        return i - j;
      }
      if (i < m and haystack[i] != needle[j]) {
        j ? j = dp[j - 1] : i++;
      }
    }
    return -1;
  }

  vector<int> KMP(string needle) {
    int n = needle.size();
    vector<int> dp(n, 0);
    // each index represents the length of longest suffix which is also a prefix
    for (int i = 1, len = 0; i < n;) {
      if (needle[i] == needle[len]) {
        dp[i++] = ++len;
      } else if (len) {
        len = dp[len - 1];
      } else {
        dp[i++] = 0;
      }
    }
    return dp;
  }
};

int main() {
  return 0;
}
