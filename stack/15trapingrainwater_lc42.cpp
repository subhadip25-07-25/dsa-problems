// two pinter approch preferable watch colsely and reviseit more 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int trap(vector<int>& height) {
        int leftmax = 0 ;
        int rightmax  = 0 ;
        int l = 0 ;
        int r = height.size()-1;
        int total = 0 ;
        while(l<r){
            if( height[l]<= height[r]){
                if( height[l] < leftmax){
                    total +=leftmax-height[l];
                }else{
                    leftmax = height[l];
                    
                }
                l++;
            }else{
                if( height[r] < rightmax){
                    total +=rightmax-height[r];
                }else{
                    rightmax = height[r];
                   
                }
                 r--;
            }
        }
        return total;
    }
};