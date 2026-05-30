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
    void helper( TreeNode* root, vector<vector<int>>&res){
        queue<TreeNode*>qu;
        
        if( root == NULL)return ;
        qu.push(root);
        while(!qu.empty()){
            int currsize= qu.size();
            vector<int>ans;
            while(currsize--){
                TreeNode*curroot= qu.front();
                ans.push_back(curroot->val);
                qu.pop();
                if( curroot->left){
                    qu.push(curroot->left);
                }
                if( curroot->right){
                    qu.push(curroot->right);
                }
            }
            res.push_back(ans);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        helper(root, ans);
        return ans;
    }
};