#include <bits/stdc++.h>

using namespace std;

class QuickUnion
{
    private:
        int *id;
        int *size;
        int root(int i)
        {
            while(i != id[i])
            {
                // path compression
                id[i] = id[id[i]]; 
                i = id[i];
            }
            return i;
        }
    
    public:
        QuickUnion(int n)
        {
            id = new int[n * sizeof(int)];
            size = new int[n * sizeof(int)];
            for(int i=0 ; i<n ; i++)
            {
                id[i] = i;
                size[i] = 1;
            }
        }

        bool find(int p, int q)
        {
            return root(p) == root(q);
        }

        void unite(int p, int q)
        {
            int i = root(p);
            int j = root(q);
            if(size[i] < size[j])
            {
                id[i] = j;
                size[j] += size[i]; 
            } else {
                id[j] = i;
                size[i] = size[j];
            }
        }
};

int main()
{
    QuickUnion *q = new QuickUnion(10);
    q -> unite(1, 2);
    cout << q -> find(1, 2) << endl;
    q -> unite(4, 5);
    q -> unite(6, 7);
    cout << q -> find(4, 5) << endl;
    cout << q -> find(5, 6) << endl;
    q -> unite(5, 6);
    cout << q -> find(5, 6) << endl;
    return 0;
}
