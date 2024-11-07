#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100;
vector<int> adj[MAX];  
bool visited[MAX];  
vector<pair<int, int>> result; 

// Функция поиска в глубину (DFS)
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            result.push_back({ v, u });
            dfs(u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    dfs(0);


    for (auto edge : result) {
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }

    return 0;
}
