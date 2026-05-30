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
int answercount( TreeNode *root,int  targetsum,  long long  currsum, unordered_map<long int , int> m){
    if(root ==NULL){
          return 0;
    }
    int anscount;
    currsum+=root->val;
    anscount=m[currsum-targetsum];// we dont use mp.find cuz Because operator[] returns 0 for non-existing keys, which is exactly what we need. Also, inserting a zero-frequency key doesn’t affect correctness in this problem.
    m[currsum]++;
    anscount+=answercount(root->left,targetsum , currsum , m)+answercount(root->right, targetsum , currsum, m);
    m[currsum]--;
    return anscount;
}
    int pathSum(TreeNode* root, int targetsum) {
        unordered_map<long int,int>m;
        m[0]=1;
        return answercount(root, targetsum, 0 , m);
    }
};