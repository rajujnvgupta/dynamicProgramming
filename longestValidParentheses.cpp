/*
    author @rajujnvgupta  
    28/oct/2019
*/
#include <bits/stdc++.h>
using namespace std;
string str;
int longestValidParentheses(string s) {
        
        int ans = 0;
        stack<int>st;
        
        st.push(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                st.push(i+1);
            }
            else if(s[i]==')'){
                
                if(st.size() == 1){
                    st.pop();
                    st.push(i+1);
                }
                else{
                    
                    st.pop();
                    int tp = st.top();
                    ans = max(ans, i+1 - tp);    
                }
            }
        }
        return ans;
    }

int main(){
    ///enter string having char '(' or ')'
    cin>>str;
    cout<<solve(str)<<endl;
}

