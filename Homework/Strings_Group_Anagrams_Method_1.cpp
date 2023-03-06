#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// strings are sorted and them mapped

vector<vector<string>> groupAnagrams(vector<string>& strs){
    map<string, vector<string>>mp;

    for(auto str:strs){
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
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

// TC: O(N*klog(k))