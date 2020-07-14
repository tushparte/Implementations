#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> g[], vector<bool>& visited, int s, stack<int>& stk) {
    visited[s] = true;
    for (auto x: g[s]) {
        if (!visited[x])
            dfs(g, visited, x, stk);
    }
    stk.push(s);
}


string findOrder(string dict[], int N, int k) {
    vector<int> g[k];
    for (int i = 1; i < N; ++i) {
        string s1 = dict[i - 1];
        string s2 = dict[i];
        int l = min(s1.size(), s2.size());
        for (int j = 0; j < l; ++j) {
            if (s1[j] != s2[j]) {
                char in = s2[j];
                char out = s1[j];
                g[out - 'a'].push_back(in - 'a');
                break;
            }
        }
    }
    stack<int> stk;
    vector<bool> visited(k, false);
    for (int i = 0; i < k; ++i) {
        if (!visited[i])
            dfs(g, visited, i, stk);
    }
    string res = "";
    while (!stk.empty()) {
        res += 'a' + stk.top();
        stk.pop();
    }
    return res;
}
