#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& in_degree) {
    int n = graph.size();
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            --in_degree[neighbor];
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result.size() == n ? result : vector<int>{ -1 };
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        ++in_degree[to];
    }

    vector<int> result = topologicalSort(graph, in_degree);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
