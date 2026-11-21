#pragma once
#include "ProductGroup.h"
#include <vector>

class DeliveryPlanner {
private:
    std::vector<ProductGroup> products;
public:
    void addProduct(const ProductGroup& p);
    void editProduct(int index, const ProductGroup& p);
    void deleteProduct(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    int getSize() const;
    ProductGroup getProduct(int index) const;
    void clear();
    void reorderProducts(const std::vector<int>& order);


    double planDelivery(std::vector<int>& order, std::vector<double>& profits, double& baseProfit, double& greedyProfit, double& improvement, double& percent) const;
};
