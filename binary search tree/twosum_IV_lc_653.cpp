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
    void inorder(TreeNode* root, vector<int>&v ){
        if( root == NULL)return;
        inorder( root ->left,v);
        v.push_back( root->val);
        inorder( root ->right,v);
    }
    bool ispresent( vector<int>&v, int target){
        int l = 0;
        int r = v.size()-1;
        while( l<r){
            if( v[l]+v[r]== target){
                return true;
            }
          if( v[l]+v[r]> target){
                r--;
            }
            if( v[l]+v[r]< target){
                l++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder ( root , v);
       return ispresent(v,k);
    }
};
bool helper(TreeNode* root, unordered_set<int>& st, int k){
    if(root == NULL) return false;

    if(st.count(k - root->val)) return true;

    st.insert(root->val);

    return helper(root->left, st, k) || helper(root->right, st, k);
}