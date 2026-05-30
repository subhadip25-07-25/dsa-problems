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

      TreeNode* anstree(vector<int>& preorder, vector<int>& postorder,unordered_map<int, int>&postmap, int prest
      ,int prend, int postst,int postend){

         if(prest>prend || postst>postend){return NULL;}
         TreeNode*root = new  TreeNode (preorder[prest]);
         if(prest == prend){return root;}
         int leftchildval= preorder[prest+1];
         int leftsubtreeidx= postmap[leftchildval];
         int leftsubtreesize = leftsubtreeidx+1-postst;

         root->left= anstree(preorder,postorder, postmap,prest+1,leftsubtreesize+prest,postst, leftsubtreeidx );
         root->right = anstree(preorder,postorder, postmap,leftsubtreesize+prest+1,prend,leftsubtreeidx+1, postend-1 );
         return root ;
      }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int>postmap;
        for(int i = 0 ; i<preorder.size(); i++){
            postmap[postorder[i]]= i ;
        }
        return anstree(preorder,postorder, postmap,0,preorder.size()-1,0,postorder.size()-1);
    }
};