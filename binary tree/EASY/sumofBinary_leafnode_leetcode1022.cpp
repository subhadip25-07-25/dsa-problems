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
 int sum = 0;
 int convert(string path){
    int decimal = 0 ;
    int power = 1;
    for( int i = path.size()-1 ; i>= 0; i --){
          if(path[i]=='1'){
            decimal+=power;
          }
          power= power*2;
    }
    return decimal;
 }
    void totalsum(TreeNode* root, string path){
        if(root ==NULL)return;
        path+=to_string(root->val);
        if( root ->left ==NULL && root ->right ==NULL){
            sum+=convert(path);
            return ;
        }
        totalsum(root->left, path);
        totalsum(root->right, path);
    }
    int sumRootToLeaf(TreeNode* root) {
        string path="";
        totalsum(root, path);
        return sum;
    }
};