#include<iostream>
#include<vector>
using namespace std;

int mincostTicketsHelper(vector<int>&days, vector<int>&costs, int i){
    // Base case

    // Solution for 1 case
    // 1 day pass taken
    int cost1 = costs[0] + mincostTicketsHelper(days, costs, i+1);

    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j < days.size() && days[j] <= passEndDay){
        j++;
    }
    int cost7 = costs[1] + mincostTicketsHelper(days, costs, j); 

    // 30 day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j < days.size() && days[j] <= passEndDay){
        j++;
    }
    int cost30 = costs[2] + mincostTicketsHelper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int>&days, vector<int>&costs){
    return mincostTicketsHelper(days, costs, 0);
}

int main(){
    vector<int>days{1, 4, 6, 7, 8, 20};
    vector<int>costs{2, 7, 15};
    cout << mincostTickets(days, costs) << endl;
    return 0;
}