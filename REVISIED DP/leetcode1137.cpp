#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
vector<int>dp;
  int solver( int n){
    if( n ==0)return 0;
    if( n == 1 || n ==2)return 1;
    if( dp[n]!= -1)return dp[n];
    return dp[n]= solver( n-1)+solver(n-2)+solver(n-3);
  }
  int solver_tbu( int n){
     if( n ==0)return 0;
    if( n == 1 || n ==2)return 1;
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for( int i =3 ; i<=n ; i++){
        dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
  }
    int tribonacci(int n) {
        dp.clear();
        // dp.resize(n+2, -1);
        // return solver(n);
        dp.resize( n+2, 0);
        return solver_tbu(n);
    }
};
int main(){
    return 0;
}