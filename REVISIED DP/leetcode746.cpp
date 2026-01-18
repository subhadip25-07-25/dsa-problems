#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

vector<int>dp;
 int helper(vector<int>& cost,int idx){
    int n = cost.size();
         if(idx>=n){return 0;}
         if(dp[idx]!=-1)return dp[idx];
         int thstep= helper(cost, idx+1)+cost[idx];
         int ndstep= helper(cost,idx+2)+cost[idx];
         return dp[idx]= min(thstep,ndstep);
 }
 int helper_tbu(vector<int>& cost){
    int n = cost.size();
       dp[n]=0;
       dp[n+1] = 0;        
       for(int i = n-1; i>=0; i--){
        dp[i]= min(dp[i+1],dp[i+2])+cost[i];
       }
       return min (dp[0],dp[1]);
 }
    int minCostClimbingStairs(vector<int>& cost) {
    //    dp.resize(cost.size()+1,-1);
    //    return min(  helper(cost,0), helper(cost,1));

       dp.clear();
       dp.resize(cost.size()+2,0);
       return helper_tbu(cost);
    }
};