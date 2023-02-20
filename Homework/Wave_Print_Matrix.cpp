#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>>v){
    int row = v.size();
    int col = v[0].size();
    for(int startCol = 0; startCol < col; startCol++){
        // Even no of cols -> Top to bottom
        if((startCol&1) == 0){
            for(int i = 0; i < row; i++){
                cout << v[i][startCol] << " ";
            }
        }
        else{
        // Odd no of cols -> Bottom to top
            for(int i = row-1; row >= 0; row--){
                cout << v[i][startCol]<< " ";
            }
        }
    }
}

int main(){
    vector<vector<int> > v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    wavePrintMatrix(v);
    return 0;
}