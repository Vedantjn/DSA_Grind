#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// Using maps and vector
// int hash[256] = {0}
// is same as
// std::array<int, 256> hash = {0};

std::array<int, 256> hash(string s){
    std::array<int, 256>hash = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    
    map<std::array<int, 256>, vector<string>>mp;

    for(auto str:strs){
        mp[hash(str)].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ans.push_back(it->second);
    }
    return ans;
}

int main(){
    vector<string>strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << groupAnagrams(strs) << endl;
}

// TC: O(n*k)
// sC: O(n*k)