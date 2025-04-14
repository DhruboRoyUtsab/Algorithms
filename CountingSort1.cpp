#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int Size, int max)
{
    // Initialize Count array with size max + 1 and set all elements to 0
    int Count[max + 1] = {0};

    // Count the occurrences of each element in the input array
    for (int i = 0; i < Size; i++) {
        int n = arr[i];
        Count[n]++;
    }

    // Update Count array to store cumulative counts
    for (int i = 1; i <= max; i++)
        Count[i] = Count[i] + Count[i - 1];

    int sortedArr[Size];

    // Build the sorted array
    for (int j = Size - 1; j >= 0; j--) {
        sortedArr[Count[arr[j]] - 1] = arr[j];
        Count[arr[j]]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < Size; i++) {
        arr[i] = sortedArr[i];
    }
}

// Driver code
int main()
{
    int inputArray[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int N = sizeof(inputArray) / sizeof(inputArray[0]);

    countSort(inputArray, N, 12); // Sort the input array

    for (int i = 0; i < N; i++) // Print the sorted array
        cout << inputArray[i] << " ";
}
