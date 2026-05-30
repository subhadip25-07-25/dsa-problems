#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
vector<vector<int>>dp;
  int helper(vector<vector<int>>& triangle, int row , int col){
    if(row == triangle.size()-1){
        return triangle[row][col];
    }
    if(dp[row][col]!= INT_MIN)return dp[row][col];
    int step= helper(triangle,row+1,col)+triangle[row][col];
    int dstep= helper(triangle,row+1,col+1)+triangle[row][col];
    return dp[row][col]=min(step,dstep);
  }
  int helper_tbu(vector<vector<int>>& triangle){
    // takes the no of row  = 4 
    int row = triangle.size();
// cpoy the last row 
    for(int i = 0 ; i<= triangle[row-1].size()-1; i++){
          dp[row-1][i]= triangle[row-1][i];
    }
    // st filling from bottom
    for(int i = row - 2; i>=0 ; i--){
        // filling col 
        for(int j = 0 ; j<triangle[i].size(); j++){
            dp[i][j]= triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
  }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        dp.resize(205,vector<int>(205,INT_MIN));
        return helper_tbu(triangle);
      //  return helper(triangle,0, 0);
    }
};