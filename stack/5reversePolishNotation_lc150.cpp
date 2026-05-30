#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<string>& v , stack <int>&st){
        for(int i = 0 ; i< v.size() ; i++){
            if( !st.empty() && v[i]== "+"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c = a+b;
                st.push(c);
            }
           else if( !st.empty() && v[i]== "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c = a-b;
                st.push(c);
            }
           else if( !st.empty() && v[i]== "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c = a*b;
                st.push(c);
            }
           else if( !st.empty() && v[i]== "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c = a/b;
                st.push(c);
            }
            else{
                st.push(stoi(v[i]));
            }
        }
        return st.top();
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        return helper( tokens ,st);
    }
};