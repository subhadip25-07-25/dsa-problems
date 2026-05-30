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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if( root == NULL)return NULL;
        if( root == p || root ==q)return root ;
        TreeNode* la = lca( root->left , p ,q);
        TreeNode* ra = lca( root->right , p , q);
        if( la && ra){
            return root ;
        }
        if( la == NULL && ra != NULL)return ra;
        // if( ra ==NULL && la != NULL)return la;
        // if( la == NULL && ra == NULL)return NULL;
        // better 
        else if( la ==NULL){
            return ra;
        }else{
            return la ;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p , q);
    }
};