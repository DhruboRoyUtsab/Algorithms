#include<iostream>
using namespace std;

void merge(int *arr,int low,int high,int mid){

        int i = low; int j= mid+1;

        int c[high - low + 1];
        int k = 0;
        
        while(i <= mid && j <= high){
            if(arr[i] < arr[j]){
                c[k++] = arr[i++];
            }
            else{
                c[k++] = arr[j++];
            }
        }
        while(i <= mid){
            c[k++] = arr[i++];
        }
        while(j <= high){
            c[k++] = arr[j++];
        }

        for(i = low; i <= high; i++){
            arr[i] = c[i - low];
        }
    }
    void mergeSort(int *arr,int low,int high){
        int mid =(low+high)/2;
        if(low<high){
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,high,mid);
    
        }
    }
    void printArray(int arr[],int size){
        for(int i = 0; i<size;i++){
            cout<<arr[i]<<" ";
            }
            cout<<endl;
    }
   int main(){
        int arr[] ={5,2,3,1};
        int size = sizeof(arr)/sizeof(arr[0]);
        mergeSort(arr,0,size-1);
        printArray(arr,size);

    }