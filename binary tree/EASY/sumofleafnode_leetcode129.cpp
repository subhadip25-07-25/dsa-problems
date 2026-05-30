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
int sum ;
    void sumofleaf(TreeNode* root, string path){
        if( root == NULL)return ;
        path= path+to_string(root->val);
        if( root ->left ==NULL && root->right ==NULL){
            sum = sum +stoi(path);
        }
        sumofleaf(root->left, path);
        sumofleaf(root->right, path);
    }
    // sumofleaf worked but insted of stoi we need to do better 
    void sumofleafbetter(TreeNode* root, int sumofleafnode){
        if( root == NULL)return ;
         sumofleafnode= sumofleafnode *10+ root->val;
        if( root ->left ==NULL && root->right ==NULL){
            sum+= sumofleafnode ;
           
        }
        sumofleafbetter(root->left,sumofleafnode);
        sumofleafbetter(root->right,sumofleafnode);
    }
    int sumNumbers(TreeNode* root) {
        //string path="";
        sum = 0 ;
        //sumofleaf(root, path);
        sumofleafbetter(root,0);
        return sum;
    }
};