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
  bool haspath( TreeNode* root, int target , int sum){
    if( root == NULL)return false;
    sum += root->val;
    if( root ->left ==NULL && root->right == NULL){
        if( sum == target)return true ;
    }
    return haspath(root->left , target , sum) || haspath(root->right , target , sum);
  }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if we use sum as global we need to backtrack at last ,  but it complex 
        return haspath(root ,targetSum , 0 );
    }
};