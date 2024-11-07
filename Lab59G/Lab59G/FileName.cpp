#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<string> operations(k);
    vector<pair<int, int>> queries;
    vector<bool> is_cut(k, false);

    for (int i = 0; i < k; ++i) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        operations[i] = op;
        if (op == "cut") {
            queries.push_back({ u, v });
            is_cut[i] = true;
        }
        else if (op == "ask") {
            queries.push_back({ u, v });
        }
    }

    DSU dsu(n);
    vector<bool> result;

    for (int i = k - 1; i >= 0; --i) {
        if (operations[i] == "cut") {

            int u = queries[i].first;
            int v = queries[i].second;
            dsu.unite(u, v);
        }
        else if (operations[i] == "ask") {

            int u = queries[i].first;
            int v = queries[i].second;
            result.push_back(dsu.connected(u, v));
        }
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << (result[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}
