#include "HashTable.h"
#include <fstream>

void HashTable::insert(const std::string& key, const std::string& value) {
    int idx = hashFunc(key);
    int start = idx;
    do {
        if (!table[idx].occupied || table[idx].deleted) {
            table[idx].key = key;
            table[idx].value = value;
            table[idx].occupied = true;
            table[idx].deleted = false;
            count++;
            return;
        }
        if (table[idx].key == key) {
            table[idx].value = value;
            return;
        }
        idx = (idx + 1) % size;
    } while (idx != start);
}

std::string HashTable::search(const std::string& key) const {
    int idx = hashFunc(key);
    int start = idx;
    do {
        if (!table[idx].occupied && !table[idx].deleted) return "";
        if (table[idx].occupied && table[idx].key == key) return table[idx].value;
        idx = (idx + 1) % size;
    } while (idx != start);
    return "";
}

void HashTable::remove(const std::string& key) {
    int idx = hashFunc(key);
    int start = idx;
    do {
        if (!table[idx].occupied && !table[idx].deleted) return;
        if (table[idx].occupied && table[idx].key == key) {
            table[idx].occupied = false;
            table[idx].deleted = true;
            return;
        }
        idx = (idx + 1) % size;
    } while (idx != start);
}


void HashTable::loadFromFile(const std::string& filename) {
    for (auto& entry : table) {
        entry = Entry();
    }
    count = 0;

    std::ifstream file(filename);
    if (!file.is_open()) return;
    std::string word, hint;
    while (file >> word >> hint) {
        insert(word, hint);
    }
    file.close();
}

void HashTable::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;
    for (const auto& entry : table) {
        if (entry.occupied) {
            file << entry.key << " " << entry.value << "\n";
        }
    }
    file.close();
}

std::vector<std::pair<std::string, std::string>> HashTable::getAll() const {
    std::vector<std::pair<std::string, std::string>> result;
    for (const auto& entry : table) {
        if (entry.occupied) {
            result.push_back({ entry.key, entry.value });
        }
    }
    return result;
}
