#include "GridTask.h"
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>

GridTask::GridTask() : rows(0), cols(0) {}

void GridTask::clear() {
    data.clear();
    rows = cols = 0;
}

void GridTask::create(int r, int c) {
    clear();
    rows = r;
    cols = c;
    data.resize(rows * cols, 0.0);
}

void GridTask::setCell(int r, int c, double value) {
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        data[r * cols + c] = value;
}

double GridTask::getCell(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        return data[r * cols + c];
    return 0;
}

void GridTask::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return;
    out << rows << " " << cols << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            out << getCell(i, j);
            if (j + 1 < cols) out << " ";
        }
        out << "\n";
    }
}

void GridTask::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;
    int r, c;
    in >> r >> c;
    create(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            in >> data[i * c + j];
}

int GridTask::getRows() const { return rows; }
int GridTask::getCols() const { return cols; }

double GridTask::solvePath(int r1, int c1, int r2, int c2, std::vector<std::pair<int, int>>& path) const {
    if (r2 < r1 || c2 < c1) return -1;
    int R = r2 - r1 + 1;
    int C = c2 - c1 + 1;
    std::vector<double> dp(R * C, std::numeric_limits<double>::max());
    std::vector<int> prev(R * C, -1);

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            double cost = getCell(r1 + i, c1 + j);
            int idx = i * C + j;
            if (i == 0 && j == 0) {
                dp[0] = cost;
                prev[0] = -1;
            }
            else {
                double best = std::numeric_limits<double>::max();
                int bestIdx = -1;
                if (i > 0 && dp[(i - 1) * C + j] < best) {
                    best = dp[(i - 1) * C + j];
                    bestIdx = (i - 1) * C + j;
                }
                if (j > 0 && dp[i * C + j - 1] < best) {
                    best = dp[i * C + j - 1];
                    bestIdx = i * C + j - 1;
                }
                if (i > 0 && j > 0 && dp[(i - 1) * C + j - 1] < best) {
                    best = dp[(i - 1) * C + j - 1];
                    bestIdx = (i - 1) * C + j - 1;
                }
                dp[idx] = cost + best;
                prev[idx] = bestIdx;
            }
        }

    path.clear();
    int idx = R * C - 1;
    while (idx != -1) {
        int i = idx / C;
        int j = idx % C;
        path.push_back({ r1 + i, c1 + j });
        idx = prev[idx];
    }
    std::reverse(path.begin(), path.end());
    return dp[R * C - 1];
}

