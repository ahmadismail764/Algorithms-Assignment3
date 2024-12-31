#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int k = 1; k < n; ++k)
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < n; ++j)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int answer = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            answer += dist[i][j];
    string bitString = bitset<32>(answer).to_string();
    int firstNonZero = bitString.find_first_not_of('0');
    cout << bitString.substr(firstNonZero) << '\n';
}