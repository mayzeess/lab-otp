#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9;
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < k; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        dist[a][b] = l;
    }

    floydWarshall(dist, n);

    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] != INF) {
                sum += dist[i][j];
                count++;
            }
        }
    }

    if (count > 0) {
        cout << fixed << setprecision(6) << (sum / count) << endl;
    }
    else {
        cout << "0.000000" << endl;
    }

    return 0;
}
