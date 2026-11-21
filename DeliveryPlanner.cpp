#include "DeliveryPlanner.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

void DeliveryPlanner::addProduct(const ProductGroup& p) {
    products.push_back(p);
}

void DeliveryPlanner::editProduct(int index, const ProductGroup& p) {
    if (index >= 0 && index < products.size())
        products[index] = p;
}

void DeliveryPlanner::deleteProduct(int index) {
    if (index >= 0 && index < products.size())
        products.erase(products.begin() + index);
}

int DeliveryPlanner::getSize() const {
    return (int)products.size();
}

ProductGroup DeliveryPlanner::getProduct(int index) const {
    if (index >= 0 && index < products.size())
        return products[index];
    return ProductGroup();
}

void DeliveryPlanner::clear() {
    products.clear();
}

void DeliveryPlanner::reorderProducts(const std::vector<int>& order) {
    std::vector<ProductGroup> newProducts;
    for (int idx : order) {
        if (idx >= 0 && idx < products.size())
            newProducts.push_back(products[idx]);
    }
    products = newProducts;
}

double DeliveryPlanner::planDelivery(std::vector<int>& order, std::vector<double>& profits, double& baseProfit, double& greedyProfit, double& improvement, double& percent) const {
    int size = (int)products.size();
    if (size == 0) return 0.0;
    std::vector<ProductGroup> sorted = products;
    order.clear();
    profits.clear();

    baseProfit = 0;
    for (int i = 0; i < size; i++) {
        double profit = (i + 1 <= products[i].allowedDays) ? products[i].price : products[i].price / 2;
        baseProfit += profit;
    }

    std::sort(sorted.begin(), sorted.end(), [](const ProductGroup& a, const ProductGroup& b) {
        return a.daysLeft < b.daysLeft;
        });

    greedyProfit = 0;
    for (int i = 0; i < size; i++) {
        double profit = (i + 1 <= sorted[i].allowedDays) ? sorted[i].price : sorted[i].price / 2;
        greedyProfit += profit;
        auto it = std::find(products.begin(), products.end(), sorted[i]);
        order.push_back(std::distance(products.begin(), it));
        profits.push_back(profit);
    }


    improvement = greedyProfit - baseProfit;
    percent = (baseProfit == 0) ? 0 : (improvement / baseProfit) * 100;
    return greedyProfit;
}

void DeliveryPlanner::saveToFile(const std::string& filename) const
{
    std::ofstream out(filename);
    if (!out.is_open()) return;

    out << "Name,Price,DaysLeft,AllowedDays\n";
    for (const auto& p : products) {
        out << p.name << ','
            << std::fixed << std::setprecision(2) << p.price << ','
            << p.daysLeft << ','
            << p.allowedDays << '\n';
    }
    out.close();
}

void DeliveryPlanner::loadFromFile(const std::string& filename) {
    products.clear();
    std::ifstream file(filename);
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        std::istringstream iss(line);
        std::string name, priceStr, daysLeftStr, allowedDaysStr;
        if (std::getline(iss, name, ',') &&
            std::getline(iss, priceStr, ',') &&
            std::getline(iss, daysLeftStr, ',') &&
            std::getline(iss, allowedDaysStr, ',')) {
            double price = std::stod(priceStr);
            int daysLeft = std::stoi(daysLeftStr);
            int allowedDays = std::stoi(allowedDaysStr);
            products.emplace_back(name, price, daysLeft, allowedDays);
        }
    }
}


