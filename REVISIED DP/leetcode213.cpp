#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> dp;
    int maxprofit(vector<int>& nums, int i , int end) {
        
        if (i> end)
            return 0;
        
        if (dp[i] != -1){
            return dp[i];
        }
        int inc = maxprofit( nums, i+2 , end)+ nums[i];
        int exc= maxprofit(nums, i+1, end);
        return dp [i]= max( inc,exc);
    }
    int maxprofit_tbu( vector<int>&nums , int st ,int end){
        int n = nums.size();
        vector<int>dp( n+2, 0 );
        for( int i = end ; i >= st ; i-- ){
            dp[i]=max ({dp[i+2]+nums[i], dp[i+1]});
        }
        return dp[st];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n ==1 )return nums[0];
        // dp.clear();
        // dp.resize( nums.size()+2, -1);
        // int case1 = maxprofit( nums , 1, n-1);
        // dp.clear();
        // dp.resize( nums.size()+2, -1);
        // int case2 = maxprofit(nums, 0 , n-2);
        // return max( case1 , case2);

        // tbu 
        int case1 = maxprofit_tbu( nums,1, n-1);

        int case2 = maxprofit_tbu( nums, 0,n-2);
        return max( case1 , case2);

    }
};