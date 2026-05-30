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
   int time ;
   void timeneed(TreeNode* root, unordered_map<TreeNode*, TreeNode* >&mp,TreeNode* stnode ){
    unordered_set<int>infected;
    
    queue<TreeNode*>qu;
    qu.push(stnode);
    infected.insert(stnode->val);
    while(!qu.empty()){
        int currlevel = qu.size();
        bool flag = false;
        while(currlevel--){
            TreeNode*currnode = qu.front();
            qu.pop();
            if(currnode->left && !infected.count(currnode->left->val)){
                infected.insert(currnode->left->val);
                qu.push(currnode->left);
                flag = true;
            }
            if(currnode->right && !infected.count(currnode->right->val)){
                infected.insert(currnode->right->val);
                qu.push(currnode->right);
                flag = true;
            }
            if( mp[currnode] && !infected.count(mp[currnode]->val)){
                infected.insert(mp[currnode]->val);
                qu.push(mp[currnode]);
                flag =true;
            }

        }
        if( flag){
            time++;
        }
    }
    

   }
   TreeNode*position(TreeNode* root,unordered_map<TreeNode*, TreeNode* >&mp, int start){
    if(root ==NULL)return NULL;
    TreeNode*startnode;
    queue<TreeNode*>qu;
    qu.push(root );
    while(!qu.empty()){
        int currsize = qu.size();
       
        while(currsize--){
            TreeNode* currnode = qu.front();
           
            if(currnode->val == start){
                startnode = currnode;
            }
            qu.pop();
            if(currnode->left!=NULL){
                qu.push(currnode->left);
                mp[currnode->left]=currnode;
            }
            if(currnode->right!=NULL){
                qu.push(currnode->right);
                mp[currnode->right]=currnode;
            }
        }


    }
    return startnode;
   }
    int amountOfTime(TreeNode* root, int start) {
        time = 0 ;
        unordered_map<TreeNode*, TreeNode*>mp;
        TreeNode*stnode= position(root , mp , start);
    timeneed(root , mp , stnode);
        return time;

    }
};