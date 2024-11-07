#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int N, S, F;
    cin >> N >> S >> F;
    S--;
    F--;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                graph[i][j] = INF;
            }
        }
    }

    vector<int> dist(N, INF);
    vector<int> parent(N, -1);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, S });

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (int to = 0; to < N; ++to) {
            if (graph[v][to] != INF) {
                int len = graph[v][to];
                if (dist[v] + len < dist[to]) {
                    dist[to] = dist[v] + len;
                    parent[to] = v;
                    pq.push({ dist[to], to });
                }
            }
        }
    }
    if (dist[F] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    for (int v = F; v != -1; v = parent[v]) {
        path.push_back(v + 1);
    }

    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
