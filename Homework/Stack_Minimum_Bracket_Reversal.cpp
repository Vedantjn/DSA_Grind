int countRev(string s){
    // If odd size strin, the n impossible to make pairrs
    if(s.size() & 1) return -1;

    int ans = 0;
    stack<chat>st;

    for(char ch:st){
        if(ch == '{'){
            st.push('{');
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    // Stack is still non empty, let's count reversals
    while(!st.empty()){
        char a = st.top();
        st.pop();

        char b = st.top();
        st.pop();

        if(a==b){
            ans+=1;
        }
        else{
            ans+=2;
        }
    }
    return ans;
}