#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, graph, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& reverse_graph, vector<bool>& visited, vector<int>& components, int component_num) {
    visited[node] = true;
    components[node] = component_num;
    for (int neighbor : reverse_graph[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, reverse_graph, visited, components, component_num);
        }
    }
}

vector<int> kosaraju(int N, vector<vector<int>>& graph, vector<vector<int>>& reverse_graph) {
    vector<bool> visited(N, false);
    stack<int> st;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);

    vector<int> components(N, -1);
    int component_num = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            dfs2(node, reverse_graph, visited, components, component_num++);
        }
    }

    return components;
}

int main() {
    int n, n;
    cin >> n >> n;

    vector<vector<int>> graph(n);
    vector<vector<int>> reverse_graph(n);

    for (int i = 0; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        graph[from].push_back(to);
        reverse_graph[to].push_back(from);
    }

    vector<int> components = kosaraju(n, graph, reverse_graph);
    int num_components = *max_element(components.begin(), components.end()) + 1;

    cout << num_components << endl;
    for (int component : components) {
        cout << component + 1 << " ";
    }
    cout << endl;

    return 0;
}
