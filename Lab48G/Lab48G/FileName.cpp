#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, length;
};

double find_average_distance(int N, const vector<vector<Edge>>& graph) {
    // ����� ���� ���������� �����
    long long total_distance = 0;
    // ���������� ���, ����� �������� ���������� ����
    int count = 0;

    // ������� �������� ��� ���������� ���������� ����� �� ����� �������
    auto dijkstra = [&](int start) {
        vector<int> dist(N + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if (d > dist[v]) continue;

            for (const Edge& edge : graph[v]) {
                if (dist[edge.to] > dist[v] + edge.length) {
                    dist[edge.to] = dist[v] + edge.length;
                    pq.push({ dist[edge.to], edge.to });
                }
            }
        }
        return dist;
        };

    // ������ �������� ��� ������ �������
    for (int i = 1; i <= N; ++i) {
        vector<int> dist = dijkstra(i);
        for (int j = 1; j <= N; ++j) {
            if (i != j && dist[j] != INF) {
                total_distance += dist[j];
                ++count;
            }
        }
    }

    return (double)total_distance / count;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<Edge>> graph(N + 1);

    // ������ �����
    for (int i = 0; i < K; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({ b, l });
    }

    // ���������� � ����� ����������
    cout.precision(6);
    cout << fixed << find_average_distance(N, graph) << endl;

    return 0;
}
