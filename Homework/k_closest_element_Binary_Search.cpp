#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int lowerBound(vector<int>&nums, int x){
    int start = 0;
    int end = nums.size()-1;
    int ans = end;

    while(start <= end){
        int mid = (start+end)/2;
        if(nums[mid] >= x){
            ans = mid;
            end = mid-1;
        }
        else if(x > nums[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

vector<int>binarySearchMethod(vector<int>&nums, int k, int x){
    // lower bound
    int h = lowerBound(nums, x);
    int l = h-1;

    while(k--){
        if(l < 0){
            h++;
        }
        else if(h >= nums.size()){
            l--;
        }
        else if(x-nums[l] < nums[h]-x){
            h++;
        }
        else{
            l--;
        }
    }
    return vector<int> (nums.begin()+l+1, nums.begin()+h);
}

vector<int>findClosestElements(vector<int>&nums, int k, int x){

    return binarySearchMethod(nums, k, x);
}

int main(){

    vector<int>nums{1,2,3,4,5};
    int k = 4;
    int x = 3;

    cout << findClosestElements(nums, k, x);

}