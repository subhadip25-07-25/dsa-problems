#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
      void helper( vector<int>&v , stack<int>& st ,  vector<int>&ans ){
        for( int i=0 ; i< v.size() ; i++){
            while( !st.empty() &&  v[i]> v[st.top()]){
                ans[st.top()]= (i - st.top());
                st.pop();
            }
            st.push(i);
        }
       
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(), 0 );
        stack <int>st;
        helper( temperatures , st , ans );
        return ans ;
    }
};