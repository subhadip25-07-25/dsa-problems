
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

class Solution {
public:
   void pathfinder(TreeNode* root, string path , vector<string>&ans){
    if( root ==NULL)return ;
    if(!path.empty()){// if path is not empty
          path+="->";
     }
     // why we add before adding root cuz if we dont 1->2->3->get a extrea ->at last 
     path+=to_string(root->val);//store the root first 
     
     if( root->left ==NULL && root->right ==NULL){// we hit the leaf node we get an valid path
          ans.push_back(path);
     }
     pathfinder( root->left, path , ans);
     pathfinder(root->right, path , ans);
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string  p ="";
        pathfinder(root, p ,ans);
        return ans;
    }
};




// class Solution {
// public:
//     vector<string> pathfinder(TreeNode* root) {
//         vector<string> res;
//         if (!root) return res;

//         // Leaf node: return the current value as the only path
//         if (!root->left && !root->right) {
//             res.push_back(to_string(root->val));
//             return res;
//         }

//         // Traverse left subtree
//         if (root->left) {
//             vector<string> leftPaths = pathfinder(root->left);
//             for (string path : leftPaths) {
//                 res.push_back(to_string(root->val) + "->" + path);
//             }
//         }

//         // Traverse right subtree
//         if (root->right) {
//             vector<string> rightPaths = pathfinder(root->right);
//             for (string path : rightPaths) {
//                 res.push_back(to_string(root->val) + "->" + path);
//             }
//         }

//         return res;
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         return pathfinder(root);
//     }
// };
