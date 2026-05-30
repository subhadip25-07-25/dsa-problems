#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void helper(vector<int>&v , stack<int>&st){
    for( int i =0 ; i< v.size()  ; i++ ){
        if( v[i]< 0){
           while( !st.empty() && st.top()>0 && abs(v[i])> st.top()){
            st.pop();
           }
           if(!st.empty() && abs(v[i])==st.top() ){
            st.pop();
           }
         else if( st.empty() || st.top()<0 ){
            st.push(v[i]);
           }

        }else{
            st.push(v[i]);
        }
    }
  }
    vector<int> asteroidCollision(vector<int>& asteroids) {
      
        stack<int>st;
        helper(asteroids,st);
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};