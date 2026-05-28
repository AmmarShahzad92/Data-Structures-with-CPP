#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
// Function to merge two unsorted linked lists into a sorted linked list
Node* mergeAndSort(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    // Append the second list to the first list
    Node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2;

    // Sort the merged list using bubble sort
    bool swapped;
    do {
        swapped = false;
        Node* current = head1;

        while (current && current->next) {
            if (current->data > current->next->data) {
                // Swap the data
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    return head1;
}
// Function to insert a node at the beginning of the list
Node* push(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to merge two unsorted linked lists into a sorted linked list
Node* mergeAndSort(Node* head1, Node* head2) {
    // Append the second list to the first list
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2;

    // Sort the merged list using bubble sort
    bool swapped;
    do {
        swapped = false;
        Node* current = head1;
        Node* prev = nullptr;

        while (current && current->next) {
            if (current->data > current->next->data) {
                // Swap the data
                swap(current->data, current->next->data);
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);

    return head1;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Create first unsorted list
    list1 = push(list1, 3);
    list1 = push(list1, 1);
    list1 = push(list1, 4);

    // Create second unsorted list
    list2 = push(list2, 2);
    list2 = push(list2, 5);
    list2 = push(list2, 6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* sortedList = mergeAndSort(list1, list2);

    cout << "Sorted Merged List: ";
    printList(sortedList);

    return 0;
}