#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STRING = 100;

char** inventory = nullptr;
int capacity = 2;
int size = 0;

void expandArray() {
    int newCapacity = capacity * 2;
    char** newInventory = new char*[newCapacity];
    for (int i = 0; i < size; i++) {
        newInventory[i] = new char[MAX_STRING];
        strcpy(newInventory[i], inventory[i]);
    }
    for (int i = 0; i < size; i++) {
        delete[] inventory[i];
    }
    delete[] inventory;
    inventory = newInventory;
    capacity = newCapacity;
    cout << "Array expanded to capacity: " << capacity << endl;
}

void addItem(const char* item) {
    if (size == capacity) {
        expandArray();
    }
    inventory[size] = new char[MAX_STRING];
    strcpy(inventory[size], item);
    size++;
}

const char* getItem(int index) {
    if (index >= 0 && index < size)
        return inventory[index];
    return "Invalid index";
}

void deleteItem(int index) {
    if (index >= 0 && index < size) {
        delete[] inventory[index];
        for (int i = index; i < size - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        size--;
        cout << "Item deleted at index " << index << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void printInventory() {
    cout << "Inventory (size: " << size << ", capacity: " << capacity << "): ";
    for (int i = 0; i < size; i++) {
        cout << inventory[i] << " ";
    }
    cout << endl;
}

int main() {
    inventory = new char*[capacity];
    addItem("Mouse");
    addItem("Keyboard");
    printInventory();

    addItem("Monitor"); // triggers expansion
    addItem("Laptop");
    printInventory();

    cout << "Item at index 2: " << getItem(2) << endl;

    deleteItem(1);
    printInventory();

    return 0;
}
