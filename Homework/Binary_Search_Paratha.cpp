#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossibleSolution(vector<int>cookRanks, int nP, int mid){
    int currP = 0; // Initial cooked parantha count
    for(int i = 0; i < cookRanks.size(); i++){
        int R = cookRanks[i], j = 1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*R <= mid){
                ++currP;
                timeTaken+=j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= nP){
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int>cookRanks, int nP){
    int start = 0;
    int highestRank = *max_element(cookRanks.begin(), cookRanks.end());
    int end = highestRank*( nP * (nP + 1) /2);
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(isPossibleSolution(cookRanks, nP, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int nP, nC;
        cin >> nP >> nC;
        vector<int>cookRanks;
        while(nC--){
            int R;
            cin >> R;
            cookRanks.push_back(R);
        }

        cout << minTimeToCompleteOrder(cookRanks, nP) << endl;
    }
    return 0;
}