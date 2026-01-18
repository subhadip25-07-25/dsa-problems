#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
class Solution {
public:
 vector<int>dp;
 int ways=0;
  int  distinct_ways(int n , int i){
      if(i == n){
       return 1;
      }
      if(i>n)return 0;
      if(dp[i]!= -1){
        return dp[i];
      }
     return dp[i]= distinct_ways(n, i+1)+distinct_ways(n, i+2);
       
  }
  int distinct_waystab(int n  ){
      vector<int>dp(n+2, 0);
      dp[n]= 1;
      for( int i = n-1; i >= 0 ; i--){
        dp[i]= dp[i+1]+dp[i+2];
      }
      return dp[0];
  }
    int climbStairs(int n) {
        //   dp.clear();
        //   dp.resize(n+1,-1);
        //   return distinct_ways(n,0);
        return distinct_waystab(n);
    }
};
int main(){
    return 0 ;
}