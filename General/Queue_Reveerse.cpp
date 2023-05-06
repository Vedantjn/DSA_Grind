#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int>&q){
    stack<int> s;

    // Step 1 : Put all elements of q into the stack
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // Step 2 : Put all elements from stack into the queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

}

void reverseQueueRecursion(queue<int>&q){
    // Base case
    if(q.empty()){
        return;
    }

    // step 1
    int temp = q.front();
    q.pop();

    // step 2
    reverseQueueRecursion(q);

    // step 3
    q.push();
}

int main(){

    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);

    cout << "Printing Queue :" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}