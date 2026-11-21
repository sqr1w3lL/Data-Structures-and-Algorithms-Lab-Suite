#pragma once
#pragma comment(lib, "User32.lib")
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <windows.h>

struct Company {
    std::string name;
    std::string address;
    int year;
    int month;
    double profit;
};

class Heap {
private:
    std::vector<Company> heap;

    void heapify(size_t n, size_t i) {
        size_t largest = i;
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;

        if (l < n && heap[l].profit > heap[largest].profit) largest = l;
        if (r < n && heap[r].profit > heap[largest].profit) largest = r;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapify(n, largest);
        }
    }

public:
    Heap() {}

    std::vector<Company> getAll() const {
        return heap;
    }

    void buildHeap(const std::vector<Company>& arr) {
        heap = arr;
        size_t n = heap.size();
        for (size_t i = n / 2; i-- > 0;) {
            heapify(n, i);
        }
    }

    void heapSort() {
        size_t n = heap.size();

        for (size_t i = n / 2; i-- > 0;) {
            heapify(n, i);
        }

        for (size_t i = n - 1; i > 0; i--) {
            std::swap(heap[0], heap[i]);
            heapify(i, 0);
        }
    }

    size_t getSize() const {
        return heap.size();
    }

    Company getValue(size_t idx) const {
        return heap[idx];
    }

    void save() {
        std::ofstream out("HeapBase.txt");
        for (const Company& c : heap)
            out << c.name << "," << c.address << "," << c.year << "," << c.month << "," << c.profit << "\n";
        out.close();
        MessageBoxA(NULL, "Дані збережено у файл!", "Успех", MB_OK | MB_ICONINFORMATION);
    }

    void load() {
        std::ifstream in("HeapBase.txt");
        std::string line;
        heap.clear();
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            Company c;
            std::getline(ss, c.name, ',');
            std::getline(ss, c.address, ',');
            std::string year, month, profit;
            std::getline(ss, year, ',');
            std::getline(ss, month, ',');
            std::getline(ss, profit, ',');
            c.year = std::stoi(year);
            c.month = std::stoi(month);
            c.profit = std::stod(profit);
            heap.push_back(c);
        }
        in.close();
    }
};
