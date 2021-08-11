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

int subsetSum(vector<int>& nums, int s) {
  int dp[s + 1] = { 0 };
  dp[0] = 1;
  for (int n : nums)
    for (int i = s; i >= n; i--)
      dp[i] += dp[i - n];
  return dp[s];
}

/** 
 * @return number of ways to make sum s using repeated coins
 */
public static int coinrep(int[] coins, int s) {
    int[] dp = new int[s + 1]; 
    dp[0] = 1;          
    for (int coin : coins)      
        for (int i = coin; i <= s; i++)         
            dp[i] += dp[i - coin];                                  
    return dp[s];
}                                       
                                            
/**
 * @return number of ways to make sum s using non-repeated coins
 */
public static int coinnonrep(int[] coins, int s) {
    int[] dp = new int[s + 1];
    dp[0] = 1;  
    for (int coin : coins)
        for (int i = s; i >= coin; i--)
            dp[i] += dp[i - coin];              
    return dp[s];                                                   
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}
