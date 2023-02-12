#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] <<" ";
    }

    cout <<endl;
}

int main(){

    vector<int>arr{0, 1, 0, 1, 1, 0, 1, 0, 1, 1};

    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

    // Left me saare 0, right me saare 1
    while(start <= end){
        if(arr[i] == 0){
            // swap from left
            swap(arr[i], arr[start]);
            i++;
            start++;
        }
        if(arr[i] == 1){
            // swap from right
            swap(arr[i], arr[end]);
            end--;
        }
    }
    printArray(arr);

}