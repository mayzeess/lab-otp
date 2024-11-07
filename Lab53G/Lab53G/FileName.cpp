#include <iostream>
#include <vector>
#include <algorithm> // Для функции std::min
using namespace std;

const int INF = 1e9; // Бесконечность, если путь недоступен

// Алгоритм Флойда
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
    int n, m; // n - количество вершин, m - количество ребер
    cout << "Введите количество вершин и ребер: ";
    cin >> n >> m;

    // Инициализация матрицы расстояний
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Заполняем диагональ нулями (расстояние до самого себя равно 0)
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    cout << "Введите ребра в формате: u v вес_ребра" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // Для ориентированного графа
        // Если граф неориентированный, раскомментируйте следующую строку
        // dist[v][u] = w;
    }

    // Вызов алгоритма Флойда
    floydWarshall(dist, n);

    // Вывод результатов
    cout << "Матрица кратчайших расстояний:" << endl;
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
