#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 2009000999;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();

        if (d_v > dist[v])
            continue;

        for (const auto& edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({ dist[to], to });
            }
        }
    }

    return dist;
}

int main() {
    int NUM;
    cin >> NUM;
    while (NUM--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        int start;
        cin >> start;

        vector<int> distances = dijkstra(start, n, graph);

        for (int i = 0; i < n; ++i) {
            if (distances[i] == INF)
                cout << INF << " ";
            else
                cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
