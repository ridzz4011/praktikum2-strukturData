#include <iostream>
#include <vector>
#include <string>

// Structure to represent an item's data
struct dataItem {
    std::string name;
    int day;
    int amount;
};

int main() {
    int numItems, numDays;

    // Step 1: Input the number of items
    std::cout << "Enter the number of items: ";
    std::cin >> numItems;

    // Create a vector to store item names
    std::vector<std::string> itemNames(numItems);

    // Input item names
    for (int i = 0; i < numItems; ++i) {
        std::cout << "Enter name for item " << i + 1 << ": ";
        std::cin >> itemNames[i];
    }

    // Step 2: Input the number of days
    std::cout << "Enter the number of days: ";
    std::cin >> numDays;

    // Create a 2D vector to store item quantities for each day
    std::vector<std::vector<int>> quantities(numDays, std::vector<int>(numItems));

    // Step 3: Input quantities for each day and item
    for (int i = 0; i < numDays; ++i) {
        for (int j = 0; j < numItems; ++j) {
            std::cout << "Enter quantity of " << itemNames[j]
                      << " on day " << i + 1 << ": ";
            std::cin >> quantities[i][j];
        }
        // Optional: Add validation to ensure entered quantity is non-negative
    }

    // Step 4: Output the list
    // Print header row with item names
    std::cout << "\t";
    for (const auto& itemName : itemNames) {
        std::cout << itemName << "\t";
    }
    std::cout << std::endl;

    // Print each day's data
    for (int i = 0; i < numDays; ++i) {
        // Print day number
        std::cout << i + 1 << "\t";

        // Print quantities for all items on this day
        for (int j = 0; j < numItems; ++j) {
            std::cout << quantities[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    // Step 5: Prompt user for input element
    int inputElement;
    std::cout << "\nPlease input an element to get details: ";
    std::cin >> inputElement;

    // Step 6: Display details for the input element
    int row = (inputElement - 1) / numItems;
    int col = (inputElement - 1) % numItems;

    dataItem item;
    item.name = itemNames[col];
    item.day = row + 1;
    item.amount = quantities[row][col];

    dataItem* ItemPtr = &item;

    std::cout << "\nName: " << item.name << "\n";
    std::cout << "Date: " << item.day << "\n";
    std::cout << "Amount: " << item.amount << "\n";
    std::cout << "Address: " << ItemPtr << "\n";

    return 0;
}
