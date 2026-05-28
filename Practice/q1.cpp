#include <iostream>
#include <string>
using namespace std;

int capacity = 2;
int size = 0;

//initialize the inventory array
string* inventory = nullptr;

void expandInventory() 
{   // Function to expand the inventory array when it reaches capacity
    cout << "Initial Capacity: " << capacity << endl;
    int newCapacity = capacity * 2; // Formula to double up the inventory capacity
    string* newInventory = new string[newCapacity];
    for (int i = 0; i < size; i++) 
    {   //  for loop to traverse in the temp array to stop prev data from deleted
        newInventory[i] = inventory[i];
    }   // end of For loop

    delete[] inventory;
    
    inventory = newInventory;
    capacity = newCapacity;
    
    cout << "Final capacity: " << capacity << endl;
}   // end of expandArray()

void addItem(const string& item) 
{   // Function to add an item to the inventory
    if (size == capacity) 
    {   // if check to see if the size has reached capacity
        expandInventory();
    }   // end of if 
    inventory[size++] = item;
}   // end of addItem()

string getItem(int index) 
{   // Function to get an item from the inventory by index
    if (index >= 0 && index < size) 
    {   // if check to see if the index is valid
        return inventory[index];
    }   // end of if
    return "Invalid index";
}   // end of getItem()

void deleteItem(int index) 
{   // Function to delete an item from the inventory by index
    if (index >= 0 && index < size) 
    {   // if check to see if the index is valid
        for (int i = index; i < size - 1; i++) 
        {   // for loop to traverse the inventory array
            inventory[i] = inventory[i + 1];
        }   // end of for loop
        size--;
        cout << "Item deleted at index " << index << endl;
    }   // end of if 
    else 
    {   // else statement to see if the index is invalid
        cout << "Invalid index!" << endl;
    }   // end of else statement
}   // end of deleteItem()

void printInventory() 
{   // Function to print the current inventory
    cout << "Inventory (size: " << size << ", capacity: " << capacity << "): " << endl;
    for (int i = 0; i < size; i++) 
    {   // for loop to traverse the inventory array
        cout << inventory[i] << " " << endl;
    }   // end of for loop
}   // End of printInventory()

int main() 
{   // Main Function to implement Inventory System

    // Initializing Inventory for store
    inventory = new string[capacity];
    
    
    // Adding items to the inventory
    addItem("Mouse");
    addItem("Keyboard");
    cout << "Adding Items: " << endl;
    cout << "Mouse" << endl;
    cout << "Keyboard" << endl;
    cout << "Inventory Size: " << size << endl;
    printInventory();

    addItem("Monitor");  // triggers expansion
    addItem("Laptop");
    printInventory();

    cout << "Item at index 2: " << getItem(2) << endl;

    deleteItem(1);
    printInventory();

    delete[] inventory;  // Clean up
    return 0;
}   // End of Main()
