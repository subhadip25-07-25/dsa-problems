#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
vector<int>dp;
    
    int helper_tbu(vector<int>& days, vector<int>& cost){
        int n = days.size();
        dp[n]=0;
        for(int idx = n-1; idx>=0; idx--){
              int single_day_pass= cost[0]+dp[idx+1];
              int i ;
                 for( i = idx ; i<n && days[i]<days[idx]+7;i++);
             int  weekly_pass= cost[1]+dp[i];
              for(i = idx ; i<n && days[i]<days[idx]+30;i++);
           int  monthly_pass= cost[2]+dp[i];

           dp[idx]=min({single_day_pass,weekly_pass,monthly_pass});
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.clear();
        dp.resize(days.size()+1,INT_MAX);
        return helper_tbu(days,costs);
    }
};