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
  // worst case 0(n2) but good soln 
  class Solution {
public:
    TreeNode*bstpreorderhelper(vector<int>& preorder,int st, int end){
        if(st>end){
            return NULL;
        }
        int rootval = preorder[st];
        TreeNode*root= new TreeNode(rootval);
        int j = st+1;
        while( j<=end &&preorder[j]<rootval){
            j++;
        }
        root->left= bstpreorderhelper(preorder,st+1,j-1);
        root->right= bstpreorderhelper(preorder,j,end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstpreorderhelper(preorder,0,preorder.size()-1);
    }
};
class Solution {
public:
    // bound tech optimal 
    TreeNode* helper(vector<int>& preorder, int &i, int bound ){
        if( i > preorder.size()- 1  || preorder[i]> bound){
            return NULL;
        }

        TreeNode*root = new TreeNode(preorder[i]);
        i++;
        root ->left = helper( preorder, i , root->val );
        root->right = helper(preorder , i , bound);
        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0 ;
      return  helper( preorder, i , INT_MAX);

    }
};