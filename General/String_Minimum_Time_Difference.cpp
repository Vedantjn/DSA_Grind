#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int findMinDifference(vector<string>&timePoints){
    // Step 1: Convert time string into minutes integer value
    vector<int>minutes;

    for(int i = 0; i < timePoints.size(); i++){
        string curr = timePoints[i];
        int hours = stoi(curr.substr(8, 2) );
        int min = stoi(curr.substr(3, 2));

        int totalMinutes = hours*60 + min;
        minutes.push_back(totalMinutes);
    }

    // Step 2: Sort
    sort(minutes.begin(), minutes.end());

    // Step 2: Difference nad calculate difference
    int mini = INT_MAX;
    int n = minutes.size();

    for(int i = 0; i < n-1; i++){
        int difference = minutes[i+1] - minutes[i];
        mini = min(mini, difference);
    }

    // THIS IS THE GAME
    int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
    int lastDiff2 = minutes[n-1] - minutes[0];
    int lastDiff = min(lastDiff1, lastDiff2);
    mini = min(mini, lastDiff);

    return mini;
}

int main(){
    vector<string>timePoints{"23:59", "00:00"};
    cout << findMinDifference(timePoints);   
}