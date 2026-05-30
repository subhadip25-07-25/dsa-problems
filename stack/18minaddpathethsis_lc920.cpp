#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 ;
        int add = 0 ;
        for(auto &ele: s){
            if( ele =='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    add++;
                }
            }
        }
        return open+add;//()))((
    }
};