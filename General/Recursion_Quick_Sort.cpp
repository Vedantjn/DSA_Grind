#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    // Step 1: Choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // Step 2: Find right position for pivot element and place it there
    int count = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    // Jab mai loop se bahr aya, tb mere pas pivot ki right position ka index ready h
    int rightIndex = s + count;

    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // Step 3: Left me chhote, right me bade element
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= arr[pivotElement]){
            i++;
        }
        while(arr[j] > arr[pivotElement]){
            j--;
        }

        // 2 case ho skte hain
        //A -> You found the elements to swap
        //B -> No need to swap
        if(i > pivotIndex && j < pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    // Base case
    if(s >= e){
        return;
    }

    // Partition logic
    int p = partition(arr, s, e);

    // Recursive calls
    // Pivot element -> Left
    quickSort(arr, s, p-1);

    // Pivot element -> Right
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 7;

    int s = 0;
    int e = n-1;
    quickSort(arr, s, e);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// TC: O(nlogn) 
// TC: O(n^2) in worst case