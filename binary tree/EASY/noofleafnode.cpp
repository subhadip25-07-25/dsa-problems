#include<bits/stdc++.h>
using namespace std ;
class node{
    public:
   int val ;
   node *left ;
   node* right ;

   node( int val){
     this->val  = val;
     left = right = NULL;
   }
};
int noleaf( node * root ){
    if( root ==NULL)return 0;
    int no = 0 ;
    if(root->left == NULL && root->right == NULL)return 1;
      no = no + noleaf( root->left)+ noleaf( root ->right);
      return no;
}
