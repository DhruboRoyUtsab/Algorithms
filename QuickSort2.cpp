#include<iostream>
using namespace std;
// Function to print the elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to partition the array into two halves
int partition(int arr[], int low, int high) {
    // Taking the last element as the pivot
    int pivot = arr[high];
    int i = low; // Index for the smaller element

    // Traverse the array and rearrange elements based on the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            // Swap elements if the current element is smaller than the pivot
            swap(arr[i], arr[j]);
            i++; 
            // Increment the index for the smaller element
        }
    }
    // Place the pivot element in its correct position
    swap(arr[i], arr[high]);
    return i; // Return the partition index
}

// Function to perform QuickSort
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}



int main() {
    // Initialize the array
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the unsorted array
    cout << "Unsorted array: ";
    printArray(arr, n);

    // Perform QuickSort
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}