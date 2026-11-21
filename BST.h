#pragma once
#include <string>
#include <vector>
#include <map>

struct Owner {
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string carNumber;
	std::string regDate;
};

class BST {
private:
    struct Node {
        Owner owner;
        Node* left;
        Node* right;
        Node(const Owner& o) : owner(o), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* remove(Node* node, const std::string& carNumber, bool& removed);
    Node* insert(Node* node, const Owner& o);
    Node* search(Node* node, const std::string& carNumber) const;
    void inorder(Node* node, std::vector<Owner>& result) const;
    void saveInorder(Node* node, std::ofstream& file) const;
    void countOwners(Node* node, std::map<std::string, int>& counter) const;
    void clear(Node* node);

public:

    BST();
    ~BST();

    bool remove(const std::string& carNumber);
    void insert(const Owner& o);
    bool search(const std::string& carNumber, Owner& foundOwner) const;
    std::vector<Owner> getAll() const;
    std::vector<std::string> getOwnersWithManyCars() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};
