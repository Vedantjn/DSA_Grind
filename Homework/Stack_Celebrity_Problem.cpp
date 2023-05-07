int celebrity(vector<vector<int>> &M, int n){
    stack<int>st;

    // Step 1 : Push all persons into stack
    for(int i = 0; i < n; i++){
        st.push();
    }

    // Step 2 : Run discard method to get a might be celebrity
    while(st.size()){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        // If a knows b
        if(M[a][b]){
            // a is not celebrity, b might be
            st.push(b);
        }
        else{
            // b is not celebrity, a might be
            st.push(a);
        }
    }

    // Step 3 : Check that single person is actually celebrity
    int mightBeCelebrity = st.top(); st.pop();

    // Celebrity should not know anyone
    for(int i = 0; i < n; i++){
        if(M[mightBeCelebrity][i] != 0){
            return -1;
        }
    }

    // Everybody should know celebrity
    for(int i = 0; i < n; i++){
        if(M[i][mightBeCelebrity] == 0 && i != celebrity){
            return -1;
        }
    }

    // mightBeCelebrity is the celebrity
    return mightBeCelebrity;
}

// TC : O(n)