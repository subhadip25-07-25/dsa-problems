//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std; 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
  
    vector<int> topView(Node *root) {
        
        // code here
        queue<pair<Node* , int>>qu;//eue store pair of node and col
        map<int , int>mp;//ol value
        vector<int>ans;
        if( root==nullptr)   return ans;
        qu.push({root,0});
        while( ! qu.empty ()){
            int currsize = qu .size();
           
            while( currsize--){
         pair<Node*, int> p = qu.front();
            Node* currval = p.first;
            int currcol = p.second;
            qu.pop();
            
            if (mp.find(currcol)==mp.end()){
                mp[currcol]=currval->data;
                
            }
            if( currval->left){
                qu.push({currval->left, currcol-1});
            }
            if( currval ->right){
                qu.push({currval->right, currcol+1});
            }
            }
        }
        for( auto &ele:mp){
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};