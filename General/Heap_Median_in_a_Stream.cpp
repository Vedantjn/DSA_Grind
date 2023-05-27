#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void callMedian(int &median, priority_queue<int>&maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element){

    if(minHeap.size() == maxHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = minHeap.top();
        }
        else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() > minHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
        }
    }
    else{
        // maxHeap.size() < minHeap.size()
        if(element > median){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }

    }
}

int main(){

    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    priority_queue<int>minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for(int i = 0; i < n; i++){
        int element = arr[i];
        median = callMedian(median, minHeap, maxHeap, element);
        cout << "-> "<< median << " ";
    }
    cout << endl;
    
    return 0;
}