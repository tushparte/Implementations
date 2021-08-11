#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
  private:
    vector<int> h;
    int count;
    int capacity;

  public:
    MaxHeap(int capacity) : h(capacity), count(0), capacity(capacity) {}
    MaxHeap(vector<int> v) {
      BuildHeap(v);
    }

    // O(1)
    int LeftChild(int i) {
      if (2 * i + 1 >= count) return -1;
      return 2 * i + 1;
    }

    // O(1)
    int RightChild(int i) {
      if (2 * i + 2 >= count) return -1;
      return 2 * i + 2;
    }

    // O(n)
    void BuildHeap(vector<int> v) {
      int n = v.size();
      for(auto num: v) 
        h.push_back(num);
      count = n;
      capacity = n;

      int i = (n - 1) / 2;
      while (i >= 0) {
        Heapify(i--);
      }
    }

    // O(log(n))
    void Heapify(int i) {
      int l = LeftChild(i);
      int r = RightChild(i);
      int maxElement = i;
      if (l != -1 and h[l] > h[i])
        maxElement = l;
      if (r != -1 and h[r] > h[maxElement])
        maxElement = r;
      if (maxElement != i) {
        int temp = h[maxElement];
        h[maxElement] = h[i];
        h[i] = temp;
        Heapify(maxElement);
      }
    }

    // O(log(n))
    void insert(int data) {
      h.push_back(0); // dummy element
      int i = count;
      count++;
      while (i != 0 and data > h[(i - 1) / 2]) {
        h[i] = h[(i - 1) / 2];
        i = (i - 1) / 2;
      }
      if (i < 0) i = 0;
      h[i] = data;
    }

    // O(1)
    int getMax() {
      if (count == 0) return INT_MIN;
      return h[0];
    }
    // O(log(n))
    int deleteMax() {
      int data = INT_MIN;
      if (count == 0) return data;
      data = h[0];
      h[0] = h[count-1];
      count--;
      Heapify(0);
      return data;
    }

    // O(n)
    void printHeap() {
      for(int i=0; i<count; ++i)
        cout << h[i] << "\t";
      cout << "\n";
    }
};

int main()
{
  vector<int> v = {4,1,3,2,16,9,10,14,8,7};
  MaxHeap h(v);
  h.printHeap();
  h.deleteMax();
  h.printHeap();
  h.insert(100);
  h.printHeap();
  while (h.getMax() != INT_MIN) {
    cout << h.getMax() << " ";
    h.deleteMax();
  }
  return 0;
}
