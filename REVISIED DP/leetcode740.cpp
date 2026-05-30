#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int>dp;
    unordered_map<int,int>mp;
    int maxprofit( vector<int>&val,int i  ){
       if( i >= val.size())return 0;
       if( dp[i] != INT_MIN)return dp[i];

       int inc;
       int exc;
       // if we have adj element 
       if( i < val.size()-1 && val[i+1] == val[i]+1 ){
           inc = maxprofit( val , i+2)+val[i]*mp[val[i]];
       }else{
        inc = maxprofit( val , i+1)+val[i]*mp[val[i]];
       }
       exc = maxprofit( val , i+1);
       return dp[i]= max( inc, exc);
    }
     int maxprofit_tbu( vector<int>& val){
        
        vector<int>dp( val.size()+2 , 0);
        int inc ;
        int exc;
        for( int i = val.size()- 1 ; i>=0 ; i--){
            if(  i+1 < val.size() &&  val[i+1]== val[i]+1){
                inc= dp[i+2]+val[i]*mp[val[i]];
            }else{
                inc = dp[i+1]+val[i]*mp[val[i]];
            }
            exc= dp[i+1];
         dp[i]= max( inc, exc);
        }
       
        return dp[0];
     }
    int deleteAndEarn(vector<int>& nums) {
        
         for( int i =0 ; i< nums.size(); i++){
             mp[nums[i]]++;
         }
         vector<int>val;
         for( auto &ele:mp){
            val.push_back( ele.first);
         }
         sort( val.begin(), val.end());

         dp.clear();
        //  dp.resize( val.size(), INT_MIN);
        //  return maxprofit(val, 0);
        return maxprofit_tbu(val);
    }
};