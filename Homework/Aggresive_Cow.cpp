#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<int>&stalls, int k, int mid){
    // can we place k cows with atleast mid distance between
    int c = 1;
    int pos = stalls[0];

    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - pos >= mid){
            c++;
            pos = stalls[i]; // one more cow has been placed
        }
        if(c== k) return true;
    }
    return false;

}

int solve(int n, int k, vector<int>&stalls){

    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0];

    int ans = -1;

    while(start <= end){
        int mid = (start+end) >> 1;
        if(isPossibleSolution(stalls, k, mid))
        {
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 5;
    int k = 3;
    vector<int> stalls{1,2,4,8,9};

    cout << solve(n, k, stalls);
}