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
    TreeNode* invertTree(TreeNode* root) {
        if( root ==NULL)return NULL;
        // basic a, b value swap logic 
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
 /*
 if the inverviewer say do not change the existing tree ok 
 
 class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        // create new node
        TreeNode* newRoot = new TreeNode(root->val);

        // reverse children while constructing
        newRoot->left = invertTree(root->right);
        newRoot->right = invertTree(root->left);

        return newRoot;
    }
};*/
