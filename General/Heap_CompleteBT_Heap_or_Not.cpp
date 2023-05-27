#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

pair<bool, int>solve(Node* root){
    // base case
    if(root == NULL){
        pair<bool, int>p = make_pair(true, INT_MIN);
    }

    if(root->left == NULL && root->right == NULL){
        // leaf node
        pair<bool, int>p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    if(leftAns.first == true && rightAns.first == true && root->data > leftAns.second && root->data > rightAns.second){
        pair<bool, int> make_pair(true, root->data);
        return p;
    }
    else{
        pair<bool, int> make_pair(false, root->data);
        return p;
    }
}

int main(){
    
    return 0;
}