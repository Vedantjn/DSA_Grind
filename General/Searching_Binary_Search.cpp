#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size-1;

    int mid = start + (end - start)/2;

    while(start <= end){
        int element = arr[mid];

        if(element == target){
            return mid;
        }
        if(target < element){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    // Target not found
    return -1;
}

int main()
{
    int arr[] = {2,4,5,6,22,32};
    int size = 6;
    int target = 5;

    int indexOfTarget = binarySearch(arr, size, target);

    if(indexOfTarget == -1){
        cout << "Target not found" << endl;
    }
    else{
        cout << "Target found at " << indexOfTarget << endl;
    }

}