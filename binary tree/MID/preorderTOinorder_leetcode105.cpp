
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
    
    TreeNode*anstree(vector<int>& preorder,int prest,int prend, vector<int>& inorder,int inst, int inend,  unordered_map <int,int>&inmap){
        if(prest>prend || inst>inend){
            return NULL;
        }
        // root 
        TreeNode*root = new TreeNode (preorder[prest]);
        // finding the pos of root in inorder 
        int rootidx= inmap[root->val];
        //calculate left subtree 
        int leftsubtree = rootidx-inst;
        root->left = anstree(preorder,prest+1,leftsubtree+prest,inorder,inst,rootidx-1,inmap);
        root->right= anstree(preorder,leftsubtree+prest+1,prend,inorder,rootidx+1,inend,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map <int,int>inmap;
       for(int i = 0 ; i<inorder.size(); i++){
        // storeing fequancy
        inmap[inorder[i]]=i;
       }  
       return anstree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }
};