#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int a[], int start, int end, int x){
    while(start <= end){
        int mid = (start+end)/2;

        if(a[mid] == x){
            return mid;
        }
        else if(x > a[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

// Also called: Doubling Search / Galloping Search / Strazile Search
int expSearch(int a[], int n, int x){
    if(a[0] == x){
        return 0;
    }

    int i = 1;

    while(i < n && a[i] <= x){
        i*=2;
    }
    return binarySearch(a, i/2, min(i, n-1), x);
}

int main(){

    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 13;

    int ans = expSearch(a,n,x);

    cout << ans << endl;

}

// TC: O(log(m))
// SC: O(2^(log(m) - 1))

// Applications:
// - Searchin infinite arrays
// - Better than Binary search if x is near beginning
