#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        return newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}
// INSERT AT POSITION FUNCTION
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node{value, nullptr};
    if (position == 0) {
        newNode->next = head;
        return newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (temp) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            delete newNode; // Position is out of bounds
        }
        return head;
    }
}


void display(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 25, 2); // Insert 25 at position 2
    head = insertAtPosition(head, 5, 0);  // Insert 5 at position 0

    // Display the linked list
    std::cout << "Linked List: ";
    display(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}