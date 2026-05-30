//https://www.geeksforgeeks.org/problems/largest-bst/1
// lc 333 but in premium
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

 class Solution{
public:

    class NodeInfo{
    public:
        int currmin;
        int currmax;
        int currsize;

        NodeInfo(int minv, int maxv, int size){
            currmin = minv;
            currmax = maxv;
            currsize = size;
        }
    };

    NodeInfo helper(Node *root){
        
        if(root == NULL){
            return NodeInfo(INT_MAX, INT_MIN, 0);
        }

        NodeInfo leftsubtree = helper(root->left);
        NodeInfo rightsubtree = helper(root->right);

        if(leftsubtree.currmax < root->data && root->data < rightsubtree.currmin){
            
            int minval = min(root->data, leftsubtree.currmin);
            int maxval = max(root->data, rightsubtree.currmax);
            int size = leftsubtree.currsize + rightsubtree.currsize + 1;

            return NodeInfo(minval, maxval, size);
        }

        return NodeInfo(INT_MIN, INT_MAX, max(leftsubtree.currsize, rightsubtree.currsize));
    }

    int largestBst(Node *root) {
        return helper(root).currsize;
    }
};
