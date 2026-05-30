//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
#include<bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
     void helper(Node* root, int key, Node* &pre , Node* &suc){
        if(root == NULL) return;

        // case 1
        if(root->data == key){

            if(root->left != NULL){
                Node* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                pre = temp;
            }

            if(root->right != NULL){
                Node* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                suc = temp;
            }
        }

        // case 2
        if(root->data < key){
            pre = root;
            helper(root->right, key , pre ,suc);
        }

        // case 3
        if(root->data > key){
            suc = root;
            helper(root->left , key , pre ,suc);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = NULL;
        Node* suc = NULL;

        helper(root , key , pre , suc);

        return {pre, suc};
    }
};