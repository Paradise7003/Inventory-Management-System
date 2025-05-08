#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

// This struct represents a product in the inventory.
// Each product has an SKU, a name, a price, and quantities for various qualities.
struct Product {
    std::string sku;                         // Unique identifier for the product
    std::string name;                        // Product name
    std::map<std::string, int> qualityQuantity; // Map to store quantities for "new", "used", and "poor" qualities
    double price;                            // Product price
};

// Initialize the inventory with some example products.
// Each product has quantities for "new", "used", and "poor" conditions.
std::vector<Product> inventory = {
    {"1001", "Laptop", {{"new", 20}, {"used", 5}, {"poor", 2}}, 999.99},
    {"1002", "Mouse", {{"new", 50}, {"used", 15}, {"poor", 10}}, 19.99},
    {"1003", "Keyboard", {{"new", 30}, {"used", 10}, {"poor", 5}}, 49.99},
    {"1010", "Pencil", {{"new", 150}, {"used", 50}, {"poor", 20}}, 0.99}
};

// Function to search for a product in the inventory by SKU or name.
// Returns a pointer to the product if found, or nullptr if not found.
Product* searchInventory(const std::string& input) {
  // Initialize the inventory with some example products.
// Each product has quantities for "new", "used", and "poor" conditions.
std::vector<Product> inventory = {
    {"1001", "Laptop", {{"new", 20}, {"used", 5}, {"poor", 2}}, 999.99},
    {"1002", "Mouse", {{"new", 50}, {"used", 15}, {"poor", 10}}, 19.99},
    {"1003", "Keyboard", {{"new", 30}, {"used", 10}, {"poor", 5}}, 49.99},
    {"1010", "Pencil", {{"new", 150}, {"used", 50}, {"poor", 20}}, 0.99},
    {"1011", "Eraser", {{"new", 200}, {"used", 80}, {"poor", 30}}, 0.49},
    {"1012", "Paper", {{"new", 500}, {"used", 200}, {"poor", 100}}, 4.99}
};
    for (auto& product : inventory) {
        // Convert both the input and product name to lowercase for a case-insensitive match
        std::string nameLower = product.name;
        std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        std::string inputLower = input;
        std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

        if (product.sku == input || nameLower == inputLower) {
            return &product; // Return the address of the product if a match is found
        }
    }
    return nullptr; // Return nullptr if no match is found
}

// Function to display all products in the inventory.
void displayInventory() {
    std::cout << "\n--- Inventory ---\n";
    for (const auto& product : inventory) {
        std::cout << "SKU: " << product.sku
            << " | Name: " << product.name
            << " | Price: $" << product.price << "\n";

        // Loop through each quality and its quantity for the product
        for (const auto& qualityQty : product.qualityQuantity) {
            std::cout << "   Quality: " << qualityQty.first
                << " | Quantity: " << qualityQty.second << "\n";
        }
    }
    std::cout << "----------------\n";
}

// Function to purchase a product from the inventory.
void purchaseProduct() {
    std::string inputNameOrSKU, quality;
    int quantity;

    std::cout << "Enter product name or SKU to purchase: ";
    std::cin >> inputNameOrSKU;

    // Search for the product in the inventory
    Product* foundProduct = searchInventory(inputNameOrSKU);
    if (foundProduct == nullptr) {
        std::cout << "Product not found!" << std::endl;
        return;
    }

    std::cout << "Found: " << foundProduct->name << " | Price: $" << foundProduct->price << "\n";
    for (const auto& qualityQty : foundProduct->qualityQuantity) {
        std::cout << "   Quality: " << qualityQty.first
            << " | Quantity: " << qualityQty.second << "\n";
    }

    std::cout << "Enter quality to purchase (New/Used/Poor): ";
    std::cin >> quality;
    std::transform(quality.begin(), quality.end(), quality.begin(), ::tolower);

    std::cout << "Enter quantity to purchase: ";
    std::cin >> quantity;

    // Check if the quality exists and if there's enough stock to fulfill the purchase
    if (foundProduct->qualityQuantity.find(quality) != foundProduct->qualityQuantity.end()) {
        if (foundProduct->qualityQuantity[quality] >= quantity) {
            foundProduct->qualityQuantity[quality] -= quantity;
            std::cout << "Purchase successful! Remaining quantity for " << quality << ": "
                << foundProduct->qualityQuantity[quality] << "\n";
        }
        else {
            std::cout << "Not enough stock available for the specified quality." << std::endl;
        }
    }
    else {
        std::cout << "Invalid quality specified." << std::endl;
    }
}

// Function to return a product to the inventory.
void returnProduct() {
    std::string inputNameOrSKU, quality;
    int quantity;

    std::cout << "Enter product name or SKU to return: ";
    std::cin >> inputNameOrSKU;

    // Search for the product in the inventory
    Product* foundProduct = searchInventory(inputNameOrSKU);
    if (foundProduct == nullptr) {
        std::cout << "Product not found!" << std::endl;
        return;
    }

    std::cout << "Returning: " << foundProduct->name << " | Price: $" << foundProduct->price << "\n";
    for (const auto& qualityQty : foundProduct->qualityQuantity) {
        std::cout << "   Quality: " << qualityQty.first
            << " | Quantity: " << qualityQty.second << "\n";
    }

    std::cout << "Enter quality to return (New/Used/Poor): ";
    std::cin >> quality;
    std::transform(quality.begin(), quality.end(), quality.begin(), ::tolower);

    std::cout << "Enter quantity to return: ";
    std::cin >> quantity;

    // Check if the quality exists and add the returned quantity to the stock
    if (foundProduct->qualityQuantity.find(quality) != foundProduct->qualityQuantity.end()) {
        foundProduct->qualityQuantity[quality] += quantity;
        std::cout << "Return successful! New quantity for " << quality << ": "
            << foundProduct->qualityQuantity[quality] << "\n";
    }
    else {
        std::cout << "Invalid quality specified." << std::endl;
    }
}

// Main menu to manage the inventory
int main() {
    int choice;
    do {
        std::cout << "\n--- Inventory Management ---\n";
        std::cout << "1. View Inventory\n";
        std::cout << "2. Search Inventory\n";
        std::cout << "3. Purchase Product\n";
        std::cout << "4. Return Product\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayInventory(); // Show all products
            break;
        case 2: {
            std::string input;
            std::cout << "Enter product name or SKU to search: ";
            std::cin >> input;

            Product* foundProduct = searchInventory(input);
            if (foundProduct == nullptr) {
                std::cout << "Product not found!" << std::endl;
            }
            else {
                std::cout << "Found: " << foundProduct->name << " | Price: $" << foundProduct->price << "\n";
                for (const auto& qualityQty : foundProduct->qualityQuantity) {
                    std::cout << "   Quality: " << qualityQty.first
                        << " | Quantity: " << qualityQty.second << "\n";
                }
            }
            break;
        }
        case 3:
            purchaseProduct(); // Purchase a product
            break;
        case 4:
            returnProduct(); // Return a product
            break;
        case 5:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
