#include<bits/stdc++.h>
using namespace std;
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
  
      void helper(TreeNode* root,TreeNode* &prev , TreeNode* &first , TreeNode* &second){
        if(root ==NULL)return;
        helper(root->left, prev , first , second);
        if( prev != NULL && prev ->val> root ->val){
            if( first == NULL){
             first = prev ;}
             second = root ;
        }
        prev = root ;
        helper( root ->right, prev , first , second);
     }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode*second = NULL;
        helper( root , prev , first , second );
        swap (first->val , second ->val);
    }
};