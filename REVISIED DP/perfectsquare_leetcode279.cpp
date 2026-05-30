#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>dp;
int helper(int n ){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
      int ans = INT_MAX;
    for(int i = 1; i*i<=n;i++){
        
          ans= min(ans, 1+helper(n-(i*i)));
    }
   return dp[n]=ans;
   
}
 int helper_tbu(int n){
    dp[0]=0;
   // in tbu i loop works for every n 
    for(int i = 1; i<=n ; i++){
       for(int j = 1 ; j*j<=n; j++){
        if(i-(j*j)>=0) {
        dp[i]= min(dp[i],1+ dp[i-(j*j)]);
        }
       }
    }
    return dp[n];
 }
    int numSquares(int n) {
        dp.clear();
        dp.resize(n+1,INT_MAX);
        return helper_tbu(n);
    }
};
