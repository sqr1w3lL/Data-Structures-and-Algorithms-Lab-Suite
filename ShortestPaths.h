#pragma once
#include <climits>

const long long INF = 1e15;

class Dijkstra {
    int n;
    long long** graph;
public:
    Dijkstra(int n);
    ~Dijkstra();
    void addEdge(int u, int v, long long w);
    long long* run(int start, int* prev);
    long long** getGraph();
};

class BellmanFord {
    struct Edge { int u, v; long long w; };
    Edge* edges;
    int m, n;
public:
    BellmanFord(int m, int n);
    ~BellmanFord();
    void addEdge(int idx, int u, int v, long long w);
    long long* run(int start, int* prev);
};

class FloydWarshall {
    int n;
    long long** dist;
    int** next;
public:
    FloydWarshall(int n);
    ~FloydWarshall();
    void loadGraph(long long** g);
    void run();
    long long** getDistances();
    int** getNext();
};
