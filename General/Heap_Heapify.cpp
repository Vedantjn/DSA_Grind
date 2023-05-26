#include<iostream>
using namespace std;

// Build a heap from array

class Heap{
    public:
    int arr[101];
    int size;

    Heap(){
        size = 0;
    }

    void insert(int value){
        // Step 1 : value inseert kro end me
        size = size+1;
        int index = size;
        arr[index] = value;

        // Step 2 : Value to correct position pr rakho
        while(index > 1){
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deletion(){
        // Step 1 : Replace root node value with last node data
        arr[1] = arr[size];
        size--;


        // Step 2 : Place root node ka data on its correct position
        int index = 1;
        while(index < size){
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;

            if(left < size && arr[index] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest == index){
                // value is at correct position
                break;
            }
            else{
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }

    }
};

void heapify(int arr[], int n, int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largest = index;

    if(leftIndex < n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex < n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(index != largest){
        // Left ya right child me se koi greater than hogya current node se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }

}

void buildHeap(int arr[], int n){
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
}

// TC of buildHeap is O(n)

int main(){

    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);

    cout << "Printing values :"<< endl;
    for(int i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }       
    cout << endl;

    
    return 0;
}