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
   
    vector<int>rightside( TreeNode* root){
        vector<int>ans;
          queue<TreeNode*>qu;
          if( root ==NULL)return ans;

          qu.push( root);
          while( !qu.empty()){
            int currlevel = qu.size();
            while( currlevel){
                TreeNode*currroot= qu.front();
                qu.pop();
                if(currlevel ==1){
                     ans.push_back(currroot->val);
                }
                if( currroot->left != NULL){
                    qu.push( currroot->left);
                }
                 if( currroot->right != NULL){
                    qu.push( currroot->right);
                }
                currlevel--;
            }
          }
          return ans;

          
    }
    void dfs (TreeNode* root, int depth , vector<int>&ans ){
        if( root == NULL)return ;
        if( depth == ans.size()){
            ans.push_back(root->val);

        }
        dfs(root->right, depth+1 , ans);
        dfs(root->left, depth+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        return rightside( root);
         

    }
};