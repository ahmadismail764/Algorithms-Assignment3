#include <vector>
#include <bits/stdc++.h>
using namespace std;

int m, total;
vector<vector<int>> dp; 
vector<int> coins(m);
int solve(int currentIndex , int sum) {
    if(currentIndex == coins.size()) {
        return abs(sum - (total - sum));
    }
    if (dp[currentIndex][sum] != -1) {
        return dp[currentIndex][sum];
    }
    int sum1 = solve(currentIndex + 1, sum + coins[currentIndex]);
    int sum2 = solve(currentIndex + 1, sum);
    dp[currentIndex][sum] = min(sum1, sum2);
    return dp[currentIndex][sum];
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        cin >> m;
        coins.resize(m);
        
        for(int i = 0; i < m; i++) {
            cin >> coins[i];
        }
        total = accumulate(coins.begin(), coins.end(), 0);
        dp.assign(m + 1, vector<int>(total + 1, -1));
        cout << solve(0, 0) << endl;
    }
    return 0;
}
