#include<bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
public:
     void avg(TreeNode* root, vector<double>&res){
        if( root ==NULL)return;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            double sum =0 ;
            int size  = qu.size();
            vector<double>ans;
            while(size--){
                TreeNode*curroot= qu.front();
                ans.push_back(curroot->val);
                qu.pop();
                if(curroot->left){
                    qu.push(curroot->left);
                }
                if( curroot->right){
                    qu.push(curroot->right);
                }
            }
            for( int i = 0 ; i< ans.size(); i++){
                sum = sum +ans[i];
            }
            int n = ans.size();
            double avgval = sum/n;
            res.push_back(avgval);

        }
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        avg(root, res);
        return res;
    }
};