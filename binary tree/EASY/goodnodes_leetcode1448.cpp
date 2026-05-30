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
   int goodnode( TreeNode* root ,int max_so ){
    if( root ==NULL)return 0;
    int count = 0 ;
    if( root->val >= max_so){
         count= 1;
         max_so = root->val;
    }
     return count+ goodnode( root->left, max_so)+ goodnode( root->right,  max_so);
   }
    int goodNodes(TreeNode* root) {
        return goodnode( root , INT_MIN);
    }
};