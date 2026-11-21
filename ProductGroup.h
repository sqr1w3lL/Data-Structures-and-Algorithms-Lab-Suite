#pragma once
#include <string>

struct ProductGroup {
    std::string name;
    double price;
    int daysLeft;
    int allowedDays;

    ProductGroup() : name(""), price(0), daysLeft(0), allowedDays(0) {}
    ProductGroup(const std::string& n, double p, int d, int a)
        : name(n), price(p), daysLeft(d), allowedDays(a) {
    }

    bool operator==(const ProductGroup& other) const {
        return name == other.name &&
            price == other.price &&
            daysLeft == other.daysLeft &&
            allowedDays == other.allowedDays;
    }

};
