#include<iostream>
#include<deque>
using namespace std;

// Answer print from queue
// Removal from queue
// Insertion

void solve(int arr[], int n, int k){
    deque<int> q;

    // Process first window of size k
    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    // Remaining window processing
    for(int i = k; i < n; i++){
        // purani window ka answer dedo
        if(q.empty()){
            cout << 0 <<" ";
        }
        else{
            cout << arr[q.front()] << " ";
        }

        // Out of window elements ko remove krdo
        while((!q.empty()) && (i - q.front() >= k)){
            q.pop_front();
        }

        // Check current element for insertion
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    // Answer print karo for last window
    if(q.empty()){
        cout << 0 << " ";
    }
    else{
        cout << arr[q.front()] << " ";
    }

    
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};

    int size = 8;
    int k = 3;

    solve(arr, size, k);
    
    return 0;
}

// TC : O(n)
// SC : O(k)