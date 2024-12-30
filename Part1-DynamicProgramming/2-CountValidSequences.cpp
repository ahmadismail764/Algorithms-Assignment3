#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
string s;

bool isValid(int currentIndex) { return s[currentIndex] != 'w' && s[currentIndex] != 'm'; }

long long solve(int currentIndex)
{
    if (currentIndex < 0)
        return 1;
    if (!isValid(currentIndex))
        return 0;
    if (dp[currentIndex] != -1)
        return dp[currentIndex];
    long long result = 0;

    result = solve(currentIndex - 1);

    if (s[currentIndex] == 'n' && s[currentIndex - 1] == 'n')
        result = (result + solve(currentIndex - 2));
    if (s[currentIndex] == 'u' && s[currentIndex - 1] == 'u')
        result = (result + solve(currentIndex - 2));

    dp[currentIndex] = result;
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        dp.assign(s.size(), -1);
        cout << solve(s.size() - 1) << '\n';
    }
}
