#include<bits/stdc++.h>
using namespace std;
// leetcode 523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0 ;
        bool is_present= false;
        unordered_map<int,int>mp;
        for(int i = 0 ; i< nums.size(); i++){
            prefix+=nums[i];
            int remainder= prefix%k;
            mp[0]= -1 ;
            // in case of [2,4]
            // if(remainder%k==0){
            //     if(i+1>=2){
            //         is_present= true ;
            //     }
            // }
            // if we get same remiander so j to i is a valid subarray
            if(mp.find(remainder)!=mp.end()){
                if(i-mp[remainder]>=2){
                   is_present= true;
                }
            }else{
                mp[remainder] = i;
            }
        }
        return is_present;
    }
};
int main(){
    return 0;
}