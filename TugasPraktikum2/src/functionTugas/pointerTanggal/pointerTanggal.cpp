#include "../../../include/dataItem.hpp"

dataItem itemDetails(const std::vector<std::string>& itemNames,
                        const std::vector<std::vector<int>>& quantities,
                        int inputElement) {
    dataItem item;
    int row = (inputElement - 1) / itemNames.size();
    int col = (inputElement - 1) % itemNames.size();

    item.name = itemNames[col];
    item.day = row + 1;
    item.amount = quantities[row][col];

    return item;
}
