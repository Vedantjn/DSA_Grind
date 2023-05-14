#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string decodeString(string s){
    stack<string>st;
    for(auto ch : s){
        if(ch == ']'){
            string stringToRepeat = "";
            while(!st.empty() && !isdigit(st.top()[0])){
                string top = st.top();
                stringToRepeat+= top == "[" ? "" : top;
                st.pop();
            }

            string neumericTimes = "";
            while(!st.empty() && isdigit(st.top()[0])){
                neumericTimes+= st.top();
                st.pop();
            }
            reverse(neumericTimes.begin(), neumericTimes.end());
            int n = stoi(neumericTimes);

            // Final decoding
            string currentDecode = "";
            while(n--){
                currentDecode += stringToRepeat;
            }
            st.push(currentDecode);
        }
        else{
            string stringToRepeat(1, ch);
            st.push(stringToRepeat);
        }
    }

    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;
    return 0;
}