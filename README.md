# Inventory Management System

A simple C++ command-line application for managing product inventory with support for quality tiers, purchase/return workflows, and real-time updates. This project was developed for an introductory data structures course and demonstrates modular programming, use of STL containers, and practical fileless inventory handling.

---

## 🧾 Project Overview

This system is built to handle inventory for various products, each identified by a unique SKU and stored with different quality tiers ("new", "used", and "poor"). It includes functionality for:

- Viewing all inventory items.
- Searching for items by name or SKU.
- Purchasing items while updating stock.
- Returning items and restocking.
- Displaying price and quantity for each quality tier.

Currently, the inventory is stored in memory and resets on each program run.

---

## 💡 Features

### 1. View Inventory
- Displays all products with SKU, name, price, and available quantities by quality.

### 2. Search Inventory
- Case-insensitive search by SKU or product name.

### 3. Purchase Products
- Users specify name/SKU, quality (new/used/poor), and quantity.
- Inventory is updated in real-time if stock is sufficient.

### 4. Return Products
- Users can return items by specifying the quality and quantity.
- Stock is incremented accordingly.

### 5. Product Quality Tiers
- Each product has stock counts under:
  - `new`
  - `used`
  - `poor`

### 6. Structured Code
- Modular functions include:
  - `displayInventory()`
  - `searchInventory()`
  - `purchaseProduct()`
  - `returnProduct()`

---

## 🛠 Code Files

### 🔹 `Inventory Management Project Design.cpp`

**Main logic for the application.**  
Implements all the core features of inventory interaction including user input menus, product structure, and handling logic.

### 🔹 Project Files

- `Inventory Management Project Design.sln`
- `Inventory Management Project Design.vcxproj`
- `Inventory Management Project Design.vcxproj.filters`
- `Inventory Management Project Design.vcxproj.user`

These files are used to compile and run the project in Microsoft Visual Studio.

---

## 🔍 Example Products in Inventory

```text
SKU     Name       Quality    Quantity    Price
1001    Laptop     new        20          $999.99
                   used       5
                   poor       2
1002    Mouse      new        50          $19.99
                   ...
