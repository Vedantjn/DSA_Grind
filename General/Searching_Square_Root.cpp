#include<iostream>
#include<vector>
using namespace std;

int findSqrt(int n){
    int s = 0; 
    int e = n;
    int mid = s + (e-s)/2;

    int target = n;
    int ans;

    while(s<=e){
        if(mid*mid == target)
            return mid;
        
        if(mid*mid > target){
             // left search
            e = mid - 1;
        }
        else{
            // right search
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){

    int n;
    cout << "Enter the number "<< endl;
    cin >> n;

    int ans = findSqrt(n);
    cout << ans << endl;    

    int precision;
    cout << "Enter no. of floating digits in precision " << endl;
    cin >> precision;

    double step = 0.1;
    double finalAns = ans;
    for(int i = 0; i < precision; i++){
        for(double j = finalAns; j*j <= n; j=j+step){
            finalAns = j;
        }
        step = step / 10;
    }
    cout << finalAns;
}