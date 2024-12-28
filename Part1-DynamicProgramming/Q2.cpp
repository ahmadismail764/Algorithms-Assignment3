#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<int> dp;
string s;

    bool isValid(int currentIndex) {
        return s[currentIndex] != 'w' && s[currentIndex] != 'm';
    }

    int solve(int currentIndex) {
        if (currentIndex < 0) return 1;

        if (dp[currentIndex] != -1) return dp[currentIndex];

        if (!isValid(currentIndex)) return 0;

        long long result = 0;

        result = solve(currentIndex - 1);

        if ( s[currentIndex] == 'n' && s[currentIndex-1] == 'n') {
            result = (result + solve(currentIndex - 2)) % MOD;
        }

        if (s[currentIndex] == 'u' && s[currentIndex-1] == 'u') {
            result = (result + solve(currentIndex - 2)) % MOD;
        }

        dp[currentIndex] = result;
        return result;
    }


int main() {
    int t;cin>>t;
    while (t--) {
        cin >> s;
        dp.assign(s.size(), -1);
        cout << solve(s.size() - 1) << endl;
    }
    return 0;
}
