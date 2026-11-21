#include "ShortestPaths.h"

Dijkstra::Dijkstra(int n) : n(n) {
    graph = new long long* [n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new long long[n];
        for (int j = 0; j < n; ++j)
            graph[i][j] = (i == j ? 0 : INF);
    }
}
Dijkstra::~Dijkstra() {
    for (int i = 0; i < n; ++i) delete[] graph[i];
    delete[] graph;
}
void Dijkstra::addEdge(int u, int v, long long w) { graph[u][v] = w; }
long long** Dijkstra::getGraph() { return graph; }
long long* Dijkstra::run(int start, int* prev) {
    long long* dist = new long long[n];
    bool* used = new bool[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = INF; used[i] = false; prev[i] = -1;
    }
    dist[start] = 0;
    for (int it = 0; it < n; ++it) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!used[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (u == -1 || dist[u] == INF) break;
        used[u] = true;
        for (int v = 0; v < n; ++v)
            if (graph[u][v] != INF) {
                long long nd = dist[u] + graph[u][v];
                if (nd < dist[v]) { dist[v] = nd; prev[v] = u; }
            }
    }
    delete[] used;
    return dist;
}

BellmanFord::BellmanFord(int m, int n) : m(m), n(n) { edges = new Edge[m]; }
BellmanFord::~BellmanFord() { delete[] edges; }
void BellmanFord::addEdge(int idx, int u, int v, long long w) {
    edges[idx].u = u; edges[idx].v = v; edges[idx].w = w;
}
long long* BellmanFord::run(int start, int* prev) {
    long long* dist = new long long[n];
    for (int i = 0; i < n; ++i) { dist[i] = INF; prev[i] = -1; }
    dist[start] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (int j = 0; j < m; ++j) {
            int u = edges[j].u, v = edges[j].v;
            long long w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; prev[v] = u; updated = true;
            }
        }
        if (!updated) break;
    }
    for (int j = 0; j < m; ++j) {
        int u = edges[j].u, v = edges[j].v;
        long long w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            delete[] dist; return nullptr;
        }
    }
    return dist;
}

FloydWarshall::FloydWarshall(int n) : n(n) {
    dist = new long long* [n];
    next = new int* [n];
    for (int i = 0; i < n; ++i) {
        dist[i] = new long long[n];
        next[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            dist[i][j] = (i == j ? 0 : INF);
            next[i][j] = (i == j ? i : -1);
        }
    }
}
FloydWarshall::~FloydWarshall() {
    for (int i = 0; i < n; ++i) { delete[] dist[i]; delete[] next[i]; }
    delete[] dist; delete[] next;
}
void FloydWarshall::loadGraph(long long** g) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            dist[i][j] = g[i][j];
            if (g[i][j] != INF && i != j) next[i][j] = j;
            if (i == j) next[i][j] = i;
        }
}
void FloydWarshall::run() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                long long nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j]) {
                    dist[i][j] = nd; next[i][j] = next[i][k];
                }
            }
        }
}
long long** FloydWarshall::getDistances() { return dist; }
int** FloydWarshall::getNext() { return next; }
