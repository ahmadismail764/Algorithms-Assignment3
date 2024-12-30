#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, g, s;
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
    void reset(int n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
        fill(rank.begin(), rank.end(), 0);
    }
};

bool canBuildMST(vector<Edge>& edges, int n, int maxGold, int maxSilver, DSU& dsu) {
    dsu.reset(n + 1);
    int edgeCount = 0;
    for (auto& edge : edges) {
        if (edge.g <= maxGold && edge.s <= maxSilver) {
            if (dsu.unite(edge.u, edge.v)) {
                edgeCount++;
                if (edgeCount == n - 1) return true;
            }
        }
    }
    return false;
}

long long findMinimumCost(vector<Edge>& edges, int n, int G, int S) {
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.g < b.g;
    });

    long long result = LLONG_MAX;
    int m = edges.size();
    DSU dsu(n + 1);

    for (int i = 0; i < m; ++i) {
        int maxGold = edges[i].g;

        vector<Edge> filteredEdges;
        for (auto& edge : edges) {
            if (edge.g <= maxGold) {
                filteredEdges.push_back(edge);
            }
        }

        sort(filteredEdges.begin(), filteredEdges.end(), [](Edge& a, Edge& b) {
            return a.s < b.s; 
        });

        int l = 0, r = filteredEdges.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int maxSilver = filteredEdges[mid].s;
            if (canBuildMST(filteredEdges, n, maxGold, maxSilver, dsu)) {
                result = min(result, 1LL * maxGold * G + 1LL * maxSilver * S);
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
    }

    return result == LLONG_MAX ? -1 : result;
}

int main() {
    int n, m, G, S;
    cin >> n >> m >> G >> S;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].g >> edges[i].s;
    }

    cout << findMinimumCost(edges, n, G, S) << endl;
    return 0;
}
