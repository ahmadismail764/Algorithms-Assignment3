#include <bits/stdc++.h>
using namespace std;
int knapsack(int max_weight, const vector<pair<int, int>> &bags)
{
    vector<int> dp(max_weight + 1, 0);
    for (const auto &bag : bags)
    {
        int weight = bag.first, value = bag.second;
        for (int w = max_weight; w >= weight; --w)
            dp[w] = max(dp[w], dp[w - weight] + value);
    }
    return dp[max_weight];
}

int main()
{
    int N;
    cin >> N;
    vector<string> results;

    for (int i = 0; i < N; ++i)
    {
        int K, M;
        cin >> K >> M;
        vector<pair<int, int>> bags(M);
        for (int j = 0; j < M; ++j)
        {
            int A, B;
            cin >> A >> B;
            bags[j] = {A, B};
        }
        int max_value = knapsack(K, bags);
        results.push_back("Hey stupid robber, you can get " + to_string(max_value) + ".");
    }
    for (const string &result : results)
        cout << result << '\n';
}