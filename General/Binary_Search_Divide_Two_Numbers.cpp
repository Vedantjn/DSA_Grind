#include<iostream>
using namespace std;

int solve(int dividend, int divisor){
    int s = 0;
    int e = abs(dividend);
    int ans = 0;
    int mid = s + (e-s)/2;

    while(s<=e){
        // Perfect Solution
        if(abs(mid*divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        // Not Perfect Solution
        if(abs(mid*divisor) > abs(dividend)){
            // search in left
            e = mid - 1;
        }
        else{
            // Answer store
            ans = mid;
            // search in right 
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }

    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
        return ans;
    }
    else{
        return -ans;
    }
}

int main(){
    int dividend = 22;
    int divisor = -7;

    int ans = solve(dividend, divisor);
    cout << ans;
}