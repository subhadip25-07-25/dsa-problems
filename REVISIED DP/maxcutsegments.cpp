//https://www.geeksforgeeks.org/problems/cutted-segments1642/1
#include<bits/stdc++.h>
using namespace  std;
class Solution {
  public:
    // Function to find the maximum number of cuts.
    vector<int>dp;
    int solver( int n, int x, int y, int z ){
        if( n==0)return 0;
        if(n<0)return INT_MIN;
        if( dp[n]!=-1)return dp[n];
        int take_x=solver(n-x, x,y,z)+1;
        int take_y=solver(n-y, x,y,z)+1;
        int take_z= solver( n -z , x,y,z)+1;
        return dp[n]= max({take_x, take_y,take_z});
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        dp.clear();
        dp.resize(n+1, -1);
        
        int ans= solver(n ,x,y,z);
        if( ans
        <0){
           return 0;
        }else{
           return ans;
        }
    }
};
int main(){
    return 0;
}