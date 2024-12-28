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
        b--;
        int weight = pow(2, c);
        dist[a][b] = weight;
        dist[b][a] = weight;
    }

    for (int k = 0; k < n; ++k)
    {
        // k is the intermediate vertex we are considering
        for (int i = 0; i < n; ++i)
        {
            // i is the starting vertex
            for (int j = 0; j < n; ++j)
            {
                // j is the ending vertex
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    // If there is a path from i to k and from k to j
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    // Update the shortest path from i to j to be the minimum of the current value
                    // and the path that goes through k
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