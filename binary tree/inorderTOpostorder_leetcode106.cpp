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
 TreeNode*anstree(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&inmap,int postst,int postend,int inst, int inend){
    if(inst>inend||postst>postend){return NULL;}
    // create root node 
     TreeNode*root = new TreeNode(postorder[postend]);
     // finding the root idx 
     int rootidx = inmap[root->val];
     // size of left sub tree 
     int leftsubtree= rootidx - inst;
     root->left= anstree(inorder,  postorder, inmap, postst, postst+leftsubtree-1, inst, rootidx-1);
     root->right=anstree(inorder,  postorder, inmap,leftsubtree+postst, postend-1, rootidx+1, inend);
     return root;
 }  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inmap;
        // insert the value in inmap
        for(int i = 0 ; i<inorder.size(); i++){
            inmap[inorder[i]]=i;
        }
        return anstree(inorder,  postorder,inmap, 0 , postorder.size()-1, 0 , inorder.size()-1);
    }
};