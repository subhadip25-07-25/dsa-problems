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
  class BSTIterator {
public:
  stack<TreeNode*>st;
   void leftstore(TreeNode* root){
    while( root != NULL){
            st.push(root);
            root = root->left;
         }
   }
    BSTIterator(TreeNode* root) {
         leftstore(root);
    }
    
    int next() {
        TreeNode*temp = st.top();
        st.pop();
        leftstore(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};