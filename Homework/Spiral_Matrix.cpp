#include<iostream>
#include<vector>
using namespace std;

vector<int>spiralOrder(vector<vector<int>>&matrix){
    vector<int>ans;
    // m -> No. of Rows
    // n -> No. of Columns
    int m = matrix.size();
    int n = matrix[0].size();

    int total_elements = m*n;

    int startingRow = 0;
    int endingCol = n-1;
    int endingRow = m-1;
    int startingCol = 0;

    int count = 0;
    while(count < total_elements){
        // Print starting ka row
        for(int i = startingCol; i <= endingCol && count >= total_elements; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        // Print ending ka rcol
        for(int i = startingRow; i <= endingRow && count >= total_elements; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        // Print ending ka col
        for(int i = endingCol; i >= startingCol && count >= total_elements; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        // Print starting ka col
        for(int i = endingRow; i >= startingRow && count >= total_elements; i++){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>>v{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << spiralOrder(v);
}