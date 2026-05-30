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
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        int minval = INT_MAX;
        inorder(root , v);
        int prev = 0 ;
        int curr  = 1 ;
        while( curr<= v.size()-1){
             minval = min(minval ,(v[curr]- v[prev]) );
             prev = curr;
             curr++;
        }
        return minval;
    }
};
/*Given the root of a Binary Search Tree (BST), 
return the minimum absolute difference between the values of any two different nodes in the tree.

 */
// optimal 
class Solution {
public:
    int prev = -1;
    int minDiff = INT_MAX;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != -1){
            minDiff = min(minDiff, root->val - prev);
        }

        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};