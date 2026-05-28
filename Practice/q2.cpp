#include <iostream>
using namespace std;

// Create a linked list node structure
struct Node 
{
    int data;
    Node* next;
};

// Initialize the head of the linked list
Node* head = nullptr;

// Function to add a new node to the end of the linked list
void addNode(int value) 
{
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}


// Function to display the linked list
void displayList() 
{
    Node* temp = head;
    while (temp != nullptr) 
    {   // While loop to traverse the linked list
        cout << temp->data << " -> ";
        temp = temp->next;
    }   // end of while loop
    cout << "NULL\n";
}

// function to remove duplicates from the linked list
void removeDuplicates() 
{   
    // use a current pointer to traverse the linked list
    Node* current = head;

    // Nested While loop to check for duplicates
    while (current != nullptr && current->next != nullptr) 
    {   // While loop to traverse the linked list
        
        // Use a runner to check for duplicates
        Node* runner = current;
        
        while (runner->next != nullptr) 
        {   // While loop to check for duplicates
            
            if (runner->next->data == current->data) 
            {   // If the next node's data is equal to the current node's data1
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } 
            else 
            {   // Else if the next node's data is not equal to the current node's data
                runner = runner->next;
            }   // end of else if
        }
        current =current->next;
    }   // end of while loop
}   // end of removeDuplicates function



int main() 
{   // Main function to test the linked list and remove duplicates
    
    // Add nodes to the linked list
    int values[] = {1, 2, 3, 2, 4, 3};

    // for loop to add nodes to the linked list
    for (int val : values) 
    {
        addNode(val);
    }

    // Display the linked list before removing duplicates
    cout << "Before removing duplicates:\n";
    displayList();

    removeDuplicates();

    // Display the linked list after removing duplicates
    cout << "After removing duplicates:\n";
    displayList();

    return 0;
}   // End of main function
