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
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        int mindis = INT_MAX;
        inorder(root, v);
        int prev = 0;
        int curr = 1;
        while (curr <= v.size() - 1) {
            mindis = min(mindis, (v[curr] - v[prev]));
            prev = curr;
            curr++;
        }
        return mindis;
    }
}
;