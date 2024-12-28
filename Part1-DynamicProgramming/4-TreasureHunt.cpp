#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, w, n;
    cin >> t >> w;
    cin >> n;
    vector<pair<int, int>> treasures(n), selected;
    for (int i = 0; i < n; i++)
        cin >> treasures[i].first >> treasures[i].second;
    for (auto &t : treasures)
        t.first *= (3 * w);
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int time = treasures[i - 1].first;
        int gold = treasures[i - 1].second;
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= time)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - time] + gold);
        }
    }

    int remainingTime = t;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][remainingTime] != dp[i - 1][remainingTime])
        {
            selected.push_back(treasures[i - 1]);
            remainingTime -= treasures[i - 1].first;
        }
    }

    cout << dp[n][t] << '\n';
    cout << selected.size() << '\n';
    reverse(selected.begin(), selected.end());
    for (const auto &treasure : selected)
        cout << treasure.first / (3 * w) << ' ' << treasure.second << '\n';
}