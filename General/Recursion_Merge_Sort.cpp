#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
// void merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Assume to create arrays of len1, len2 lengths
    // int arr[n]; -> Bad practise
    int* left = new int[len1];
    int* right = new int[len2];

    // Copy values
    int k = s;
    for(int i = 0; i < len1; i++){
        left[i] = arr[k];
        k++;
    }

    k = mid+1; 
    for(int i = 0; i < len2; i++){
        right[i] = arr[k];
        k++;
    }

    // Merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){int
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else{
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // Copy logic for left array
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy logic for right array
    while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }

}

void mergeSort(int* arr, int s, int e){
    // Base case
    // s == e -> Single element
    // s > e -> Invalidarray
    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;

    // Left part sort karlo recursion
    mergeSort(arr, s, mid);

    // Right part sort karlo recursion
    mergeSort(arr, mid+1, e);

    // Now merge 2 sorted arrays
    merge(arr, s, e);

}

int main(){
    int arr[] = {4, 5, 13, 2, 12};
    int n = 5;

    int s = 0;
    int e = n-1;

    mergeSort(arr, s, e);

    // Printing the array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// TC: O(nlogn)