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
     bool validate(TreeNode* node, int minVal, int maxVal) {
    if (!node) return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;

    bool leftValid = validate(node->left, minVal, node->val);
    bool rightValid = validate(node->right, node->val, maxVal);

    if (leftValid && rightValid) {
        return true;
    } else {
        return false;
    }
}

    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }
};