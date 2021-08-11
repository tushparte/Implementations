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

int binarySearch(vector<int>& A, int B) {
  int n = A.size();
  int lo = 0, hi = n-1;
  while (lo <= hi) {
    int mid = lo+(hi-lo)/2;
    if (A[mid] == B) {
      return mid;
    } else if (A[mid] > B) {
      hi = mid-1;
    } else {
      lo = mid+1;
    }
  }
  return -1;
}

int lowerBound(vector<int>&A, int B) {
  int n = A.size();
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = lo+(hi-lo)/2;
    // feasability condition: element >= B
    if (A[mid] >= B) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  return lo;
}

int upperBound(vector<int>& A, int B) {
  int n = A.size();
  if (A[n-1] <= B) return n; // doubt if this is skippable
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = lo+(hi-lo)/2;
    // feasability condition: element > B
    if (A[mid] > B) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
  return 0;
}
