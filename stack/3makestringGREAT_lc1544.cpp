#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string helper( string &s , stack<char>&st){
        st.push(s[0]);
        for( int i = 1 ; i< s.size(); i++){
           int sval =  s[i];
           int stval = st.top();
           if(!st.empty() &&abs( sval - stval)== 32){
            st.pop();
           }else{
            st.push(s[i]);
           }
        }
        string ans = "";
        while( !st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse( ans.begin(), ans.end());
        return ans;
    }
    string makeGood(string s) {
        stack<char>st;
        return helper( s , st);
    }
};