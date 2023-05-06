#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int canCompleteGas(vector<int>&gas, vector<int>&cost){

    // Kitna petrol kam pad gya
    int deficit = 0;
    // litna petrol bacha hua h
    int balance = 0;
    // circuit kahan se start kr rhe ho
    int start = 0;

    for(int i = 0; i < gas.size(); i++){
        balance+= gas[i] - cost[i];
        if(balance < 0){
            deficit = balance;
            start = i+1;
            balance = 0;
        }
    }   

    if(deficit + balance >= 0){
        return start;
    }
    else{
        return -1;
    }
}

int main(){
    vector<int>gas{1,2,3,4,5};
    vector<int>cost{3,4,5,1,2};
    cout << canCompleteGas(gas, cost) << endl;
    return 0;
}