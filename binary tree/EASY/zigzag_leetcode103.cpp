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
    void zigzag( TreeNode* root, vector<vector<int>>&res){
        queue<TreeNode*>qu;
        int level = 0 ;
        if( root == NULL)return ;
        qu.push(root);
        while(!qu.empty()){
            int currsize= qu.size();
            vector<int>ans;
            while(currsize--){
                TreeNode*curroot= qu.front();
                ans.push_back(curroot->val);
                qu.pop();
                if( curroot->left){
                    qu.push(curroot->left);
                }
                if( curroot->right){
                    qu.push(curroot->right);
                }
            }
            level++;
            if( level%2 ==0){
             reverse(ans.begin(), ans.end());
             res.push_back(ans);
            }else{
            res.push_back(ans);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        zigzag(root, res);
        return res;
    }
};