#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueuek(queue<int>&q, int k){
    stack<int> s;
    int count = 0;
    int n = q.size();

    if(k <= 0 || k > n){
        return ;
    }

    // Step 1 : Queue k first k elements ko stack me daldo
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k){
            break;
        }

        // Step 2 : Stack se queue me waps daldo
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            q.push(temp);
        }

        // Step 3 : Push n-k lements from queue to the stack
        count = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;

            if(count == n-k){
                break;
            }
        }
    }

    // Step 2 : Put all elements from stack into the queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

}

int main(){

    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueuek(q, 2);

    cout << "Printing Queue :" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}