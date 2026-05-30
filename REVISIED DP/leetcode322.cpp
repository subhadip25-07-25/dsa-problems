#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
vector<int>dp;
  int  helper(vector<int>& coins, int amount){
        if(amount == 0 )return 0;
        if(amount<0)return INT_MAX;
        int n = coins.size();
        int res = INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        for(int i = 0 ; i<n; i++){
            int ans = INT_MAX;
           ans = helper(coins,amount-coins[i]);
           if(ans != INT_MAX){
            res = min(1+ans, res);
           }
        }
        return dp[amount]=res;
    }
     int helper_tbu(vector<int>& coins, int amount){
        dp[0]=0;
        
        for(int i = 1 ; i<= amount; i++){
            // traverse coins 
           
            for(int j = 0 ; j<coins.size(); j++ ){
              if(  i-coins[j] >=0 && dp[i-coins[j]] !=INT_MAX){
                dp[i]= min(dp[i],1+ dp[i-coins[j]]);
              }
            }
        }
        return(dp[amount]== INT_MAX?-1:dp[amount]);
     }
     const int INF = 1e9;
     int solve(int target, vector<int>& coins) {
        if (target == 0) return 0;
        if (target < 0) return INF;

        if (dp[target] != -1)
            return dp[target];

        int ans = INF;
        for (int coin : coins) {
            ans = min(ans, 1 + solve(target - coin, coins));
        }

        return dp[target] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
    //     dp.resize(amount+1, -1);
    //     int res =  helper(coins,amount);
    // if(res == INT_MAX){
    //     return -1;
    // }else{
    //     return res;
    // }
    dp.clear();
    dp.resize(amount+1,INT_MAX);
    return helper_tbu(coins,amount);
    }
};
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    const int INF = 1e9;

    int solve(int i, int target, vector<int>& coins) {
        if (target == 0) return 0;
        if (i == n || target < 0) return INF;

        if (dp[i][target] != -1)
            return dp[i][target];

        // Option 1: take current coin (unbounded, so i stays same)
        int take = 1 + solve(i, target - coins[i], coins);

        // Option 2: skip current coin
        int skip = solve(i + 1, target, coins);

        return dp[i][target] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(0, amount, coins);
        return (ans >= INF ? -1 : ans);
    }
};
