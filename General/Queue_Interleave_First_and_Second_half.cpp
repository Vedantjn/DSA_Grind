#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void interleaveQueue(queue<int>&q){
    // Step 1 : Separate both halves
    int n = q.size();
    if(q.empty()){
        return;
    }
    int k = n/2;
    int count = 0;
    queue<int>q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);

        if(count == k){
            break;
        }
    }

    // Step 2 : interleaving
    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    // Odd wala case
    if(n&1){
        int element = q.front();
        q.pop();
        q.push();
    }

}

int main(){

    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    interleaveQueue(q);

    cout << "Printing Queue :" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}