#include<iostream>
#include<vector>

using namespace std;


int main(){

    vector<int> arr{1,2,3,4};
    vector<int> brr{3,4, 5};

    vector <int> ans;

    // Outer loop on arr
    for(int i = 0; i < arr.size(); i++){
        int element = arr[i];
        // for every element, run the loop on brr
        for(int j = 0; j < brr.size(); j++){
            if(element == brr[j]){
                // mark
                brr[j] = INT_MIN;
                ans.push_back(element);
            }
        }
    }


    for(auto value : ans){
        cout << value << " ";
    }

}