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
  int maxsum = INT_MIN;
  int maxSum(TreeNode* root){
    if( root ==NULL)return 0;
        int leftmaxsum = max(0,maxSum(root->left) );// ignore negval
        int rightmaxsum= max(0,maxSum(root->right) );
        maxsum = max( maxsum , leftmaxsum+rightmaxsum+root->val);
        return root->val+max(leftmaxsum, rightmaxsum);
  }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxsum;
    }
};