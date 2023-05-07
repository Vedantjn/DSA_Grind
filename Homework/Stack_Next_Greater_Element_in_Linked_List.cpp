vector<int>nextLargerNodes(ListNode* head){
    vector<int>ll;   
    while(head){
        ll.push_back(head->val);
        head = head->next;
    }

    stack<int>st;
    vector<int>ans(ll.size()); // initialised with 0

    for(int i = 0; i < ll.size(); i++){
        while(!st.empty() && ll[i] > ll[st.top()]){
            // means ith element is the next greater of the element index present in stack
            int kids = st.top();
            st.pop();
            ans[kids] = ll[i];
        }
        st.push();
    }
    return ans;
}