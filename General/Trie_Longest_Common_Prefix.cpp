class Solution{
public:
    string longestCommonPrefix(vector<string>&strs){
        string ans="";

        // loop on first string
        for(int i = 0; i < strs[0].length(); i++){
            char ch = strs[0][i];
            bool match = true;

            // compare this character with all the remaining strings at the same index
            for(int j = 1; i < strs.size(); j++){
                // compare
                if(strs[j].size() < i || ch != strs[j][i]){
                    match = false;
                    break;
                }
            }

            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};



// #include<iostream>
// using namespace std;

// class TrieNode{
// public:

//     char data;
//     TrieNode* children[26];
//     bool isTerminal;

//     TrieNode(char d){
//         this->data = d;
//         for(int i = 0; i < 26; i++){
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };

// class Solution{
// public:


// void insertWord(TrieNode* root, string word){
//     cout << "Inserting " << word << endl;
//      // base case : 
//     // jab mera last character aega
//     if(word.length() == 0){
//         root->isTerminal = true;
//         return;
//     }
//     int childCount = 0;

//     char ch = word[0];
//     int index = ch - 'A';

//     TrieNode* child;

//     // present
//     if(root->children[index] != NULL){
//         child = root->children[index];
//     }
//     else{
//         // not present
//         child = new TrieNode(ch);
//         root->childCount++;
//         root->children[index] = child;
//     }

//     // recursion sambhal lega
//     insertWord(child, word.substr(1));

// }
    
//     void findLCP(string first, string &ans, TreeNode* root){
//         if(root->isTerminal){
//             return;
//         }

//         for(int i = 0; i < first.length(); i++){
//             char ch = first[i];

//             if(root->childCount == 1){
//                 ans.push_back(ch);
//                 int index = ch - 'a';
//                 root = root->children[root];
//             }
//             else{
//                 break;
//             }

//             if(root->isTerminal){
//                 break;
//             }
//         }
//     }

//     string longestCommonPrefix(vector<string>&strs){
//         TrieNode* root = new TrieNode('-');
//         // insert strings
//         for(int i = 0; i < strs.size(); i++){
//             insertWord(root, strs[i]);
//         }

//         string ans = "";
//         string first = strs[0];
//         findLCP(first, ans, root);
//         return ans;
//     }
// };

