#include<iostream>
using namespace std;

int partition(int arr[],int low, int high){
    
    //Taking 1st element as Pivot

    int pivot = arr[low];
    int i = low;

    for(int j = low+1; j<=high; j++){
        if(arr[j] < pivot){
            i++;//if Pivot is High then i++ will be after swap Function
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[low]); //if Pivot is High the arr[High]
    return i;
}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr, pi+1,high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}