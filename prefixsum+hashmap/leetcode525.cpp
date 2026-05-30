#include<bits/stdc++.h>
using namespace std;
int sum ;
 void maxlengh(vector<int>&v){
    if(v[0]==0){
        v[0]=-1;
    }else{
        v[0]= 1;
    }
   for(int i = 1 ; i< v.size(); i++){
    if(v[i]==1){
        v[i]=v[i]+v[i-1];}
        else{
            v[i]= -1+v[i-1];
        }
   }
   
}
int main(){
    vector<int>v={0,1,0,1,1,1};
    maxlengh(v);
    for(auto ele:v){
        cout<<ele<<"  ";
    }
    return 0 ;
}
//https://leetcode.com/problems/contiguous-array
// do later a little unserstanding map 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix= 0 ; 
        int ans = 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i =0 ; i<nums.size(); i++){
            if (nums[i]==0){
                prefix= prefix-1;
            }else{
                prefix=prefix+1;
            }
            if(mp.find(prefix)!=mp.end()){
                ans= max(ans, i-mp[prefix]);
            }else{
                mp[prefix]= i ;
            }
        }
        return ans;
    }
};