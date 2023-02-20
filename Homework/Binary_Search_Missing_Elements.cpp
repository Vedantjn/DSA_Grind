#include<iostream>
#include<vector>
using namespace std;

int findMissing(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int answer = 0;

    while(s <= e){
        if(mid == arr[mid] - 1){
            s = mid + 1;
        }
        else if((mid == arr[mid] - 2) && (mid - 1 == arr[mid - 1] - 1)){
            answer = arr[mid] - 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return answer;
    cout << answer;
}

int main(){
    vector<int> arr{1,2,3,4,6,7,8,9,10};
    int ans = findMissing(arr);
    cout << ans;
}