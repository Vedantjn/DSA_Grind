#include<iostream>
using namespace std;

class TrieNode{
public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word){
    cout << "Inserting " << word << endl;
     // base case : 
    // jab mera last character aega
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'A';

    TrieNode* child;

    // present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));

}

int main(){
    
    TrieNode* root = new TrieNode('-');

    // root->insertWord("coding");
    insertWord(root, "coding");

    return 0;
}


// TC : O(l) , l : length of word