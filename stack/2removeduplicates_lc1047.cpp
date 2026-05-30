#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string  helper( string &s , stack<char>&st){
        st.push(s[0]);
        for( int i = 1; i< s.size() ; i++){
              if(!st.empty()&& s[i]== st.top()){
                st.pop();
              }else{
                st.push(s[i]);
              }
        }
        string newstr = "";
        while( !st.empty()){
            newstr += st.top();
            st.pop();

        }
        reverse( newstr.begin(), newstr.end());
        return newstr;
    }
    string removeDuplicates(string s) {
        stack<char>st;
        return helper(s,st);
    }
}; 