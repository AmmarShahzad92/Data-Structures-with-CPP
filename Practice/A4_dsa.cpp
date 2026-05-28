#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <climits>  // Added for INT_MAX
#include <algorithm> // for std::sort and std::copy
using namespace std;
using namespace std::chrono;

//BST Node & Functions
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (!root) return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

bool bstSearch(Node* root, int key) {
    if (!root) return false;
    if (key == root->data) return true;
    else if (key < root->data)
        return bstSearch(root->left, key);
    else
        return bstSearch(root->right, key);
}

//Linear and Binary Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//Utility
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand();
}

//Main Program
int main() {
    srand(time(0));
    const int size = 1000000; // Size of the array
    // You can change the size upto 1000000
    const int reps = 1000;    // Number of repetitions for averaging since the time taken for each search can vary

    int* arr = new int[size];
    generateRandomArray(arr, size);

    int existingKey = arr[size / 2];
    int nonExistingKey = INT_MAX;
    Node* bstRoot = nullptr;

    for (int i = 0; i < size; i++) {
        bstRoot = insert(bstRoot, arr[i]);
    }

    int* sortedArr = new int[size];
    copy(arr, arr + size, sortedArr); // std::copy from <algorithm>
    sort(sortedArr, sortedArr + size); // std::sort from <algorithm>

    int choice;
    do {
        cout << "\n------ Search Algorithm Menu ------\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. BST Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n[Linear Search]" << endl;
                cout << "Data size: " << size << endl;
                cout << "Repetitions: " << reps << endl;
                auto start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    linearSearch(arr, size, existingKey);
                }
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for existing key: " << duration.count() / reps << " microseconds\n";

                start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    linearSearch(arr, size, nonExistingKey);
                }
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for non-existing key: " << duration.count() / reps << " microseconds\n";
                break;
            }
            case 2: {
                cout << "\n[Binary Search]" << endl;
                cout << "Data size: " << size << endl;
                cout << "Repetitions: " << reps << endl;
                auto start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    binarySearch(sortedArr, 0, size - 1, existingKey);
                }
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for existing key: " << duration.count() / reps << " microseconds\n";

                start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    binarySearch(sortedArr, 0, size - 1, nonExistingKey);
                }
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for non-existing key: " << duration.count() / reps << " microseconds\n";
                break;
            }
            case 3: {
                cout << "\n[BST Search]" << endl;
                cout << "Data size: " << size << endl;
                cout << "Repetitions: " << reps << endl;
                auto start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    bstSearch(bstRoot, existingKey);
                }
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for existing key: " << duration.count() / reps << " microseconds\n";

                start = high_resolution_clock::now();
                for (int i = 0; i < reps; i++) {
                    bstSearch(bstRoot, nonExistingKey);
                }
                end = high_resolution_clock::now();
                duration = duration_cast<microseconds>(end - start);
                cout << "Avg time for non-existing key: " << duration.count() / reps << " microseconds\n";
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    delete[] arr;
    delete[] sortedArr;
    return 0;
}