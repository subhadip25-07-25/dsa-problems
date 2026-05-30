#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string helper( string &s , stack <pair<char, int>>&st , int k){
        for( int i = 0 ; i< s.size() ; i++){
            if( !st.empty() && st.top().first == s[i]){
                st.top().second++;
            }
            else{
                st.push({s[i], 1});
            }
            if( st.top().second == k){
                st.pop();
            }
        }
        // stack be like (a 2 ), (b, 2)
        string ans ="";
        while( !st.empty()){
            char ch  = st .top().first;
            int count = st.top().second;
            st.pop();
            while( count --){
                ans+= ch;
            }
        }
        reverse( ans.begin(), ans.end());
        return ans;
    }
    string removeDuplicates(string s, int k) {
        stack <pair<char, int>>st;
        return helper( s , st , k);
    }
};