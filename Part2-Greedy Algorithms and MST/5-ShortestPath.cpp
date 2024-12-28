#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--; // Adjusting for 0-based indexing
        int weight = pow(2, c);
        dist[a][b] = weight;
        dist[b][a] = weight;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            answer += dist[i][j];
    string bitString = bitset<32>(answer).to_string();
    size_t firstNonZero = bitString.find_first_not_of('0');
    cout << bitString.substr(firstNonZero) << '\n';
}