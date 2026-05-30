
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
  vector<int>dp;
  int combinations( vector<int>&nums , int target ){
    if( target == 0)return 1;
    if( target <0)return 0;
    int n =nums.size();
     int ways =0 ;
     if( dp[target]!= -1 )return dp[target];
    for( int i = 0 ; i< n ; i++){
        
     ways += combinations(nums , target-nums[i]);}
    return dp[target]= ways ;
  }
  
    int combinationSum4(vector<int>& nums, int target) {
         dp.resize(target+2, -1);
         return combinations(nums , target );
    }
};