#ifndef DATAITEM_HPP
#define DATAITEM_HPP

#include <string>
#include <vector>

// Deklarasi struct dataItem untuk digunakan ke source file
struct dataItem {
    std::string name;
    int day;
    int amount;
};

// Deklarasi function dari itemDetails
dataItem itemDetails(const std::vector<std::string>& itemNames,
                        const std::vector<std::vector<int>>& quantities,
                        int inputElement);

#endif
