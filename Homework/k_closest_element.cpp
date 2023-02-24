#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<int>twoPointerMethod(vector<int>&arr, int k, int x){
    int low = 0;
    int high = arr.size()-1;

    while(high - low >= k){
        if(x-arr[low] > arr[high]-x){
            low++;
        }
        else{
            high--;
        }
    }
    vector<int>ans;
    for(int i = low; i <= high; i++){
        ans.push_back(arr[i]);
    }
    return ans;
}

vector<int>findClosestElements(vector<int>&arr, int k, int x){

    return twoPointerMethod(arr, k, x);
}

int main(){

    vector<int>nums{1,2,3,4,5};
    int k = 4;
    int x = 3;

    cout << findClosestElements(nums, k, x);

}