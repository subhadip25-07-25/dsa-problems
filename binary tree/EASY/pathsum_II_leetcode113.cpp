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
  // without backtracting
class Solution {
public:
    
    void solve(TreeNode* root, int target, int sum,
               vector<int> path,          // PASS BY VALUE
               vector<vector<int>>& res) {
        
        if (root == NULL) return;

        sum += root->val;
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                res.push_back(path);
            }
            return;
        }

        solve(root->left, target, sum, path, res);
        solve(root->right, target, sum, path, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        solve(root, targetSum, 0, path, res);
        return res;
    }
};
class Solution {
public:
   void allpath(TreeNode* root, int target, int sum , vector<vector<int>>&res, vector<int>&path){
   
     if ( root == NULL )return;
     sum += root->val;
     path.push_back(root->val);
     if( root ->left == NULL&& root->right == NULL){
        if( sum == target){
            res.push_back(path);
        }
     }
      allpath ( root->left, target,sum , res, path);
      allpath(root->right , target , sum , res, path);
      path.pop_back();
     
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>res;
        vector<int>path;
      allpath(root ,targetSum, 0 , res,path );
      return  res;
    }
};