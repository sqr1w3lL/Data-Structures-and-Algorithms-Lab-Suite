#pragma once
#include <vector>
#include <string>

class GridTask {
private:
    int rows, cols;
    std::vector<double> data;
public:
    GridTask();
    void clear();
    void create(int r, int c);
    void setCell(int r, int c, double value);
    double getCell(int r, int c) const;
    int getRows() const;
    int getCols() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    double solvePath(int r1, int c1, int r2, int c2, std::vector<std::pair<int, int>>& path) const;
};
