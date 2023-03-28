#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
    // Base case
    if(i == prices.size()){
        return;
    }

    // solution for 1  case
    if(prices[i] < minPrice){
        minPrice = prices[i];
    }
    int todaysProfit = prices[i] - minPrice;
    if(todaysProfit > maxProfit){
        maxProfit = todaysProfit;
    }

    // Recursion
    maxProfitFinder(prices, i+1, minPrice, maxProfit);
}

int maxProfits(vector<int> &prices){
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main(){
    vector<int>prices{7, 1, 5, 3, 6, 4};
    cout << maxProfits(prices) << endl;
    return 0;
}

// TC: O(n)
// SC: O(n)