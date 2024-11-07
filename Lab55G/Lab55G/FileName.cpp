#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 30000;

struct Edge {
    int u, v, weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u - 1, v - 1, w };
    }
\
    vector<int> dist(n, INF);
    dist[0] = 0;

    // Алгоритм Форда-Беллмана
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            if (dist[edge.u] < INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << INF << " ";
        }
        else {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
