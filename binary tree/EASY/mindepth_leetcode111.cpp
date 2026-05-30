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
    int helper(TreeNode* root){
        if(root ==NULL)return 0;
        int leftdepth = helper(root->left);
        int rightdepth = helper(root->right);
        // Skewed Binary Tree edge case
        // if (leftdepth == 0) return 1 + rightdepth;
        // if (rightdepth == 0) return 1 + leftdepth;
        // better 
        if(leftdepth==0 || rightdepth ==0 )return 1+ leftdepth+rightdepth;
        return 1+min(leftdepth,rightdepth);
    }
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};