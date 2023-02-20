#include<iostream>
#include<vector>
using namespace std;

void sortElements(vector<int>nums){
    // Count method
    int zeroes, ones, twos;
    zeroes = ones = twos = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeroes++;
        }
        else if(nums[i] == 1){
            ones++;
        }
        else{
            twos++;
        }
    }

    // Spread
    int i = 0;
    while(zeroes--){
        nums[i] = 0;
        i++;
    }
    while(ones--){
        nums[i] = 1;
        i++;
    }
    while(twos--){
        nums[i] = 2;
        i++;
    }
}

int main(){
    vector<int> v{1, 2, 0, 2, 1};
    sortElements(v);
}

// TC: O(n)
// SC: O(1)