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
    int sum = 0;

    void inorder(TreeNode* root, int low, int high){
        if(root == NULL) return;

        inorder(root->left, low, high);

        if(root->val >= low && root->val <= high){
            sum += root->val;
        }

        inorder(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return sum;
    }
};
// optimal 
//Inorder	O(n)	traverse whole tree
//BST pruning	O(k + log n) average	skip branches
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};