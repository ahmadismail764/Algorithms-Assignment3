#include <bits/stdc++.h>
using namespace std;

bool hasValidPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    // Create adjacency matrix
    vector<vector<int>> graph(n);
    for (const auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (current == destination)
            return true;
        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main()
{
    int n, e, source, destination;
    cout << "Enter number of vertices (n): ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (ui vi):\n";
    vector<vector<int>> edges(e, vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        if (edges[i][0] < 0 || edges[i][0] >= n ||
            edges[i][1] < 0 || edges[i][1] >= n ||
            edges[i][0] == edges[i][1])
        {
            cout << "Invalid edge!\n";
            return 1;
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;
    if (source < 0 || source >= n || destination < 0 || destination >= n)
    {
        cout << "Invalid source or destination!\n";
        return 1;
    }
    bool result = hasValidPath(n, edges, source, destination);
    cout << (result ? "true\n" : "false\n");
}