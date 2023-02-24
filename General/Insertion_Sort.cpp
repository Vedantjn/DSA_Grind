#include<iostream>
#include<vector>
using namespace std;
void printArr(vector<int>arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int round = 1;round<n;round++){ // number of rounds is n-1 for n elements
        // Step - 1 Pick the element
        int val = arr[round];
        int j = round - 1; // So that we can access outside loop
        for(;j>=0;j--){ // compare with all the elements behind the ith element
            if(arr[j] > val){
                // Do shifting operation
                arr[j+1] = arr[j];
            }
            else{
                break; // simply exit the loop 
            }
        }
        // Copying step
        arr[j+1] = val;
    }
}
int main(){
    vector<int>arr{10,1,4,8,5,7};
    cout<<"Printing before sorted "<<endl;
    printArr(arr);
    cout<<"Printing array after sorting "<<endl;
    insertionSort(arr);
    printArr(arr);
    return 0;
}

// TC: O(n^2) in normal case, O(n) in best case, O(n^2) in worst case
// SC: O(1)