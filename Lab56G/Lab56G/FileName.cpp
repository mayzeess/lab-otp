#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int weight(int i, int j) {
    return (179 * i + 719 * j) % 1000 - 500;
}

int main() {
    int n;
    cin >> n;

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int w = weight(i, j);
            if (dist[i] != INT_MAX && dist[i] + w < dist[j]) {
                dist[j] = dist[i] + w;
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}
