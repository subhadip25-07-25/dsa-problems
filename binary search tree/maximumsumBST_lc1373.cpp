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
class nodeinfo{
    public:
    int currmin;
    int currmax;
    int currsum;
    nodeinfo(int minv, int maxv , int sum){
        currmin = minv;
        currmax = maxv;
        currsum  = sum;
    }
 };
 
class Solution {

public:
int ans = 0 ;
    nodeinfo helper(TreeNode* root){
        // root null means THE LEAF NODE HAS TO BE VALID 
        if( root ==NULL)return {INT_MAX , INT_MIN  ,0 };
        // POSTORDER
        nodeinfo leftsubtree = helper(root->left);
        nodeinfo rightsubtree = helper(root->right);
        // valid bst 
        if( root->val > leftsubtree.currmax && root->val < rightsubtree.currmin){
           
           
            ans = max( ans ,leftsubtree.currsum + rightsubtree.currsum + root->val);
            return nodeinfo(min(root->val, leftsubtree.currmin),max(root->val, rightsubtree.currmax),
            leftsubtree.currsum + rightsubtree.currsum + root->val);
        }
        else{
            return nodeinfo  (INT_MIN , INT_MAX , max(leftsubtree.currsum , rightsubtree.currsum ));
        }

    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans ;
    }
};
/*
also works 

nodeinfo value{0,0,0};

value.currsum = root->val + leftsubtree.currsum + rightsubtree.currsum;
value.currmin = min(root->val , leftsubtree.currmin);
value.currmax = max(root->val , rightsubtree.currmax);

ans = max(ans , value.currsum);

return value;
*/