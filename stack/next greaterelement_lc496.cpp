#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void nge( vector<int>&v, unordered_map<int,int>&mp, stack<int>&st){
    
    for( int i = 0 ; i< v.size(); i++){
        while( !st.empty() && v[i]> v[st.top()]){
            mp[v[st.top()]] = v[i];
            st.pop();
        }
        st.push(i);
    }
    while( !st.empty()){
        mp[v[st.top()]]=-1;
        st.pop();
    }
    
  }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        vector<int>ans;
        nge(nums2 , mp , st);
        for(int i = 0 ; i<nums1.size() ; i++){
              ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};