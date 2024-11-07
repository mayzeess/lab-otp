#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    vector<long long> sum_weights;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        sum_weights.resize(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b, int weight) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }

            parent[b] = a;
            sum_weights[a] += sum_weights[b] + weight;

            if (rank[a] == rank[b])
                ++rank[a];
        }
        else {
            sum_weights[a] += weight;
        }
    }

    long long get_sum(int v) {
        return sum_weights[find(v)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y, w;
            cin >> x >> y >> w;
            dsu.unite(x, y, w);
        }
        else if (type == 2) {
            int x;
            cin >> x;
            cout << dsu.get_sum(x) << '\n';
        }
    }

    return 0;
}
