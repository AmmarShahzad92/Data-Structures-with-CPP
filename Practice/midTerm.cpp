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
