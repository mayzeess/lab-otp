#include <iostream>
#include <vector>
#include <algorithm> // ��� ������� std::min
using namespace std;

const int INF = 1e9; // �������������, ���� ���� ����������

// �������� ������
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
    int n, m; // n - ���������� ������, m - ���������� �����
    cout << "������� ���������� ������ � �����: ";
    cin >> n >> m;

    // ������������� ������� ����������
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // ��������� ��������� ������ (���������� �� ������ ���� ����� 0)
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    cout << "������� ����� � �������: u v ���_�����" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // ��� ���������������� �����
        // ���� ���� �����������������, ���������������� ��������� ������
        // dist[v][u] = w;
    }

    // ����� ��������� ������
    floydWarshall(dist, n);

    // ����� �����������
    cout << "������� ���������� ����������:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
