#pragma once
#include <string>
#include <vector>

class HashTable {
private:
    struct Entry {
        std::string key;
        std::string value;
        bool occupied;
        bool deleted;
        Entry() : key(""), value(""), occupied(false), deleted(false) {}
    };
    std::vector<Entry> table;
    int size;
    int count;

    int hashFunc(const std::string& key) const {
        unsigned int h = 0;
        for (char c : key) h = (h * 31 + c) % size;
        return h % size;
    }
public:
    HashTable(int s = 17) : table(s), size(s), count(0) {}

    void insert(const std::string& key, const std::string& value);
    std::string search(const std::string& key) const;
    void remove(const std::string& key);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    std::vector<std::pair<std::string, std::string>> getAll() const;
};
