#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int Size, int max)
{
   
    int Count[max + 1] = {0}; 

    for (int i = 0; i < Size; i++){
        int n = arr[i];
        Count[n]++;
    }
    
    for (int i = 1; i <= max; i++)
        Count[i] = Count[i] + Count[i - 1];

        int sortarr[Size];
         
    for (int i = Size - 1; i >= 0; i--){
        int n = arr[i];
        int m = --Count[n];
        sortarr[m] = n;
    }
    for (int i = 0; i <= Size; i++)
    arr[i] = sortarr[i];



}


int main()
{

    int inputArray[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int N = sizeof(inputArray) / sizeof(inputArray[0]);


    int outputArray[N];


    countSort(inputArray, N, 12);

    for (int i = 0; i < N; i++)
        cout << inputArray[i] << " ";
}