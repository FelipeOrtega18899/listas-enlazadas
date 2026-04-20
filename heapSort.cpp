#include <iostream>
#include <vector>
using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child exists and is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child exists and is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {11, 22, 25, 5, 14, 17, 2, 18};

    cout << "Original Array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}