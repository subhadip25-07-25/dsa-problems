//count number of nice subarrays
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixsum  =0 ;
        int n = nums.size();
        unordered_map<int,int>mp;
        int count = 0 ;
        mp[0]= 1;
        for(int i = 0 ; i< n ; i++){
           prefixsum = (nums[i]%2)+prefixsum;
            if(mp.find(prefixsum-k)!= mp.end()){
                count+=mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      mp[0]=1;
      int sum = 0 ;
      int count =0 ;
      for( int i = 0 ; i <nums.size(); i++){
        if( nums[i]%2 == 0) {//even 
             sum= sum+0;
        }else{
            sum=sum+1;
        }
        if(mp.count(sum-k)){
            count+=mp[sum-k];
        }
        mp[sum]++;
      }  
      return count;
    }
};
int main(){
    return 0;
}