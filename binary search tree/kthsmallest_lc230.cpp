//Given the root of a binary search tree, and an integer k, 
//return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
    void inorder(TreeNode* root, vector<int>&v){
        if( root == NULL)return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        inorder(root, v);
        int kthval = v[k-1];
        return kthval;
    }
};
class Solution {
public:

void helper(TreeNode* root, int k, int &count , int &ans){
   if( root == NULL)return;
   
   helper( root ->left , k, count, ans);
   if( count>k)return ;//after finding ans stop 
   count++;
   if( count == k){
        ans = root ->val;
        return ;
   }
   helper(root->right , k, count, ans);
}
    int kthSmallest(TreeNode* root, int k) {
    // no extra space 
    int count = 0;
    int ans = 0;
      helper(root , k, count, ans);
       return ans ;    
    }
};