#pragma once
#include <string>

class Graph {
public:
    int n;
    bool directed;
    int** adj;
    bool* visited;
    int* parent;
    int* dfs_order;
    int dfs_counter;
    int* vertex_values;

    Graph(int n_, bool directed_);
    ~Graph();

    void reset();
    void addEdge(int u, int v);
    int* BFS_path(int start, int target, int& path_len);
    void DFS_rec(int u);
    void DFS_numbering_all();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void setVertexValue(int v, int value);
};
