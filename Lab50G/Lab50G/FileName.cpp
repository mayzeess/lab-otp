#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct State {
    int value, steps;
};

int bfs(int a, int b) {
    if (a == b) {
        return 0;
    }

    queue<State> q;
    vector<bool> visited(1001, false);

    q.push({ a, 0 });
    visited[a] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int nextValue = current.value + 3;
        if (nextValue == b) {
            return current.steps + 1;
        }
        if (nextValue <= 1000 && !visited[nextValue]) {
            visited[nextValue] = true;
            q.push({ nextValue, current.steps + 1 });
        }

        nextValue = current.value * 4;
        if (nextValue == b) {
            return current.steps + 1;
        }
        if (nextValue <= 1000 && !visited[nextValue]) {
            visited[nextValue] = true;
            q.push({ nextValue, current.steps + 1 });
        }
    }

    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << bfs(a, b) << endl;

    return 0;
}
