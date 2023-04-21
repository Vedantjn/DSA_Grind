#include<iostream>
#include<vector>
using namespace std;

// Pivot at the end

void quickSort(int a[], int start, int end){
    if(start >= end) return;

    int pivot = end;
    int i = start-1;
    int j = start;

    while(j < pivot){
        if(a[j] < a[pivot]){
            ++i;
            swap(a[i], a[j]);
        }
        ++j;
    }
    ++i;
    // i is the right position for the pivot element
    swap(a[i], a[pivot]);

    quickSort(a, start, i-1);
    quickSort(a, i+1, end);
}

int main(){
    int a[] = {4, 1, 3, 9, 7};
    quickSort(a, 0, 5);
    return 0;
}

// TC : O(n^2)