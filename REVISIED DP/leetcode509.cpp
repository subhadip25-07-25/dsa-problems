
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
vector<int>dp;
   int fib_mem(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]= fib_mem(n-1)+fib_mem(n-2);
   }
   int fib_tab( int n){
    if( n == 0)return 0;
    if( n==1)return 1;
    dp[0]= 0;
    dp[1]= 1;
    for( int i = 2 ; i<=n ; i++){
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[n];
   }
   int fib_optimal( int n ){
    if( n == 0)return 0;
    if( n==1)return 1;
    int c;
    int a = 0 ;
    int b = 1 ;

    for( int i = 2 ; i<= n ; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c ;
   }
    int fib(int n) {
         dp.clear();
         dp.resize(n+1,-1);
        // return fib_mem(n);
         //return fib_tab(n);
         return fib_optimal(n);
    
    }
};