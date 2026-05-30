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
    int maxdepth(TreeNode* root){
        if( root ==NULL)return 0;
        queue<TreeNode*>qu;
        qu.push(root);
        int level = 0;
        while( !qu.empty()){
            
            int currsize = qu.size();
            while( currsize--){
                TreeNode* currroot= qu.front();
                 qu.pop();
                if( currroot->left != NULL){
                    qu.push(currroot->left);
                }
                if( currroot->right != NULL){
                    qu.push(currroot->right);
                }
            }
            level++;
            
        }
        return level;

    }
    int maxDepth(TreeNode* root) {
         return maxdepth(root);
    }
};