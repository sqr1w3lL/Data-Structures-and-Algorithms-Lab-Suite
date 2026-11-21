#include "Graph.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>

Graph::Graph(int n_, bool directed_) : n(n_), directed(directed_) {
    adj = new int* [n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++) adj[i][j] = 0;
    }
    visited = new bool[n];
    parent = new int[n];
    dfs_order = new int[n];
    vertex_values = new int[n];
    for (int i = 0; i < n; ++i) vertex_values[i] = 0;
    reset();
}

Graph::~Graph() {
    for (int i = 0; i < n; i++) delete[] adj[i];
    delete[] adj;
    delete[] visited;
    delete[] parent;
    delete[] dfs_order;
    delete[] vertex_values;
}

void Graph::reset() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        dfs_order[i] = -1;
    }
    dfs_counter = 0;
}

void Graph::addEdge(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) return;
    adj[u][v] = 1;
    if (!directed) adj[v][u] = 1;
}

int* Graph::BFS_path(int start, int target, int& path_len) {
    std::cout << "BFS from " << start << " to " << target << std::endl;
    std::cout << "Adjacency matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << adj[i][j] << " ";
        std::cout << std::endl;
    }

    path_len = 0;
    if (start < 0 || start >= n || target < 0 || target >= n) return nullptr;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) break;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[target]) return nullptr;

    int* temp = new int[n];
    int cnt = 0;
    for (int v = target; v != -1; v = parent[v]) temp[cnt++] = v;

    int* path = new int[cnt];
    for (int i = 0; i < cnt; i++) path[i] = temp[cnt - 1 - i];

    delete[] temp;
    path_len = cnt;

    std::cout << "Шлях " << path[0] << " -> " << path[cnt - 1] << ": ";
    for (int i = 0; i < cnt; ++i)
        std::cout << path[i] << " ";
    int sum = cnt - 1;
    std::cout << "(сума=" << sum << ")" << std::endl;

    return path;
}

void Graph::DFS_rec(int u) {
    visited[u] = true;
    dfs_order[u] = dfs_counter++;
    std::cout << "Вершина: " << vertex_values[u] << std::endl; 
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            parent[v] = u;
            DFS_rec(v);
        }
    }
}

void Graph::DFS_numbering_all() {
    reset();
    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS_rec(i);
    }
}

void Graph::saveToFile(const std::string& filename) const
{
    std::ofstream out(filename);
    if (!out.is_open()) return;

    out << n << " " << (directed ? 1 : 0) << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << adj[i][j] << " ";
        }
        out << "\n";
    }
    out.close();
}

void Graph::loadFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in.is_open()) return;

    int new_n, dir;
    in >> new_n >> dir;
    bool new_directed = (dir == 1);

    for (int i = 0; i < n; ++i) delete[] adj[i];
    delete[] adj;
    delete[] visited;
    delete[] parent;
    delete[] dfs_order;

    n = new_n;
    directed = new_directed;

    adj = new int* [n];
    for (int i = 0; i < n; ++i) {
        adj[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            in >> adj[i][j];
        }
    }
    visited = new bool[n];
    parent = new int[n];
    dfs_order = new int[n];
    reset();

    in.close();
}

void Graph::setVertexValue(int v, int value) {
    if (v >= 0 && v < n)
        vertex_values[v] = value;
}


