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
  // same as 102 , dont do again , we can use 102 soln and in main funtion just do reverse
  class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         if (!root) return {};

        vector<vector<int>>ans;
       queue<TreeNode*>q;
        q.push(root);
       while (!q.empty())
       {
          int size= q.size();
          vector<int>level;
          while (size--)
          {
            TreeNode*curr= q.front();
            level.push_back(curr->val);
            q.pop();
           
            if(curr->left){
                q.push(curr->left);
            }
             if(curr->right){
                q.push(curr->right);
            }
          }
          ans.push_back(level);
          
       }
       reverse(ans.begin(),ans.end());
       return ans;
    
    }
};