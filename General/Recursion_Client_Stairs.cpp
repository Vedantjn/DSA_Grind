#include<iostream>
using namespace std;

int clientStairs(int n){
    // Base case -> Stopping condition
    // 0th stair pr khade hain, islie wahan pohchne k lie 1 tareeka
    if(n == 0 || n == 1){
        return 1;
    }

    // Recursive call
    int ans = clientStairs(n-1) + clientStairs(n-2);

    return ans;
}

int main(){
    int n;
    cout << "Enter the number of stairs: " << endl;
    cin >> n;

    int ans = clientStairs(n);
    cout << "Answer is: " << ans << endl;
}

// TLE