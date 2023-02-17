#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int>v{1,3,4,4,4,4,6,7};
    int target = 4;

    auto lb = lower_Bound(v.begin(), v.end(), 4);
    cout << "Lower bound is : " << lb - v.begin();


    auto ub = upper_Bound(v.begin(), v.end(), 4);
    cout << "Upper bound is : " << up - v.begin();
}