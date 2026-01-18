#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>dp;
 int maxprofit( vector<int>&nums, int i){
    if( i >= nums.size())return 0;
    if( dp[ i] != -1){return dp[i];}
    // if u take the first house 
    int include= maxprofit( nums , i+2)+nums[i];
    int exclude = maxprofit( nums , i+1);
    return dp[i]= max(include , exclude );
 }
  int max_profit(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n+2, 0);
    for( int i = n-1 ; i>=0 ; i--){
        dp[i]=max({dp[i+1],(dp[i+2]+nums[i])});
    }
    return dp[0];
  }
    int rob(vector<int>& nums) {
        // dp . clear();
        // dp.resize(nums.size()+2, -1);
        // return maxprofit(nums, 0);
        return max_profit(nums);
    }
};
   