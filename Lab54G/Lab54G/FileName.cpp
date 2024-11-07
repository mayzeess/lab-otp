#include <iostream>
#include <vector>
using namespace std;

bool floyd(const vector<vector<int>>& matrix, int N) {
    vector<vector<int>> dist = matrix;

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (dist[i][i] == 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (floyd(matrix, N)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
