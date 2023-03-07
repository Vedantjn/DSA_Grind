#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string convert(string s, int numRows){
    if(numRows == 1){
        return s;
    }

    vector<string>zigzag(numRows);

    int i=0;
    int row = 0;

    bool direction = 1; // Top to Bottom

    while(true){
        if(direction == 1){
            while(row < numRows && i < s.size()){
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else{
            while(row >= 0 && i < s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        if(i >= s.size()) break;
        direction != direction;
    }

    string ans = "";
    for(int i = 0; i < zigzag.size(); i++){
        ans+= zigzag[i];
    } 
    return ans;

}

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl;
}