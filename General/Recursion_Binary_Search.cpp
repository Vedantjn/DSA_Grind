#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int& key){
    // Base case
    // Case 1 : Key not found
    // s > e -> Invalid array
    if(s > e){
        return -1;
    }
    int mid = s + (e - s)/2;

    // Case 2 : Key found
    if(arr[mid] == key){
        return mid;
    }
    // arr[mid] < key -> Right me search
    if(arr[mid] < key){
        return binarySearch(arr, mid+1, e, key);
    }
    // arr[mid] > key -> Left me search
    else{
        return binarySearch(arr, s, mid-1, key);
    }
}

int main(){
    vector<int>v{10, 20, 40, 60, 70, 90, 99};
    int target = 99;

    int n = v.size();

    int s = 0;
    int e = n - 1;

    int ans = binarySearch(v, s, e, target);
    cout << ans << endl;
}
