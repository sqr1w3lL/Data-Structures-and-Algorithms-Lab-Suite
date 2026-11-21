#include "BST.h"
#include <fstream>
#include <sstream>

BST::Node* BST::insert(Node* node, const Owner& o) {
    if (!node) return new Node(o);
    if (o.carNumber < node->owner.carNumber)
        node->left = insert(node->left, o);
    else if (o.carNumber > node->owner.carNumber)
        node->right = insert(node->right, o);
    return node;
}

BST::Node* BST::search(Node* node, const std::string& carNumber) const {
    if (!node || node->owner.carNumber == carNumber) return node;
    if (carNumber < node->owner.carNumber)
        return search(node->left, carNumber);
    return search(node->right, carNumber);
}

void BST::inorder(Node* node, std::vector<Owner>& result) const {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->owner);
    inorder(node->right, result);
}

void BST::saveInorder(Node* node, std::ofstream& file) const {
    if (!node) return;
    saveInorder(node->left, file);
    file << node->owner.surname << " "
        << node->owner.name << " "
        << node->owner.patronymic << " "
        << node->owner.carNumber << " "
        << node->owner.regDate << "\n";
    saveInorder(node->right, file);
}

void BST::countOwners(Node* node, std::map<std::string, int>& counter) const {
    if (!node) return;
    countOwners(node->left, counter);
    std::string key = node->owner.surname + " " + node->owner.name + " " + node->owner.patronymic;
    counter[key]++;
    countOwners(node->right, counter);
}

void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}


BST::BST() : root(nullptr) {}

BST::~BST() {
    clear(root);
}

void BST::insert(const Owner& o) {
    root = insert(root, o);
}

bool BST::search(const std::string& carNumber, Owner& foundOwner) const {
    Node* res = search(root, carNumber);
    if (res) {
        foundOwner = res->owner;
        return true;
    }
    return false;
}

std::vector<Owner> BST::getAll() const {
    std::vector<Owner> result;
    inorder(root, result);
    return result;
}

std::vector<std::string> BST::getOwnersWithManyCars() const {
    std::map<std::string, int> counter;
    countOwners(root, counter);
    std::vector<std::string> result;
    for (const auto& p : counter) {
        if (p.second > 1) {
            result.push_back(p.first + " має " + std::to_string(p.second) + " авто");
        }
    }
    return result;
}

bool BST::remove(const std::string& carNumber) {
    bool removed = false;
    root = remove(root, carNumber, removed);
    return removed;
}

BST::Node* BST::remove(Node* node, const std::string& carNumber, bool& removed) {
    if (!node) return nullptr;
    if (carNumber < node->owner.carNumber) {
        node->left = remove(node->left, carNumber, removed);
    }
    else if (carNumber > node->owner.carNumber) {
        node->right = remove(node->right, carNumber, removed);
    }
    else {
        removed = true;
        if (!node->left) {
            Node* right = node->right;
            delete node;
            return right;
        }
        else if (!node->right) {
            Node* left = node->left;
            delete node;
            return left;
        }
        Node* minLarger = node->right;
        while (minLarger->left) minLarger = minLarger->left;
        node->owner = minLarger->owner;
        node->right = remove(node->right, minLarger->owner.carNumber, removed);
    }
    return node;
}


void BST::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;
    Owner o;
    while (file >> o.surname >> o.name >> o.patronymic >> o.carNumber >> o.regDate) {
        insert(o);
    }
    file.close();
}

void BST::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;
    saveInorder(root, file);
    file.close();
}
