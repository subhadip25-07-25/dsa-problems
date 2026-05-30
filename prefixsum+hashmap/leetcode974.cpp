#include<bits/stdc++.h>
using namespace std;
//Counting Remainders to Spot Hidden Divisible Ranges 🔍
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixsum = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixsum += nums[i];
            // (((prefixsum%k)+k)%k)  why we doing this ?
            // cuz negative numbers x = -1, k = 5
            //x % k = -1
            //(-1 + 5) % 5 =4
            if (mp.find(((prefixsum % k) + k) % k) != mp.end()) {
                count += mp[((prefixsum % k) + k) % k];
            }
            mp[((prefixsum % k) + k) % k]++;
        }
        return count;
    }
};
int main(){
    cout<<9%5;
    return 0;

}
class Solution {
public:
int helper(vector<int>& nums, int k, unordered_map<int,int>&mp){
    int sum =0;
    int count = 0 ;
    mp[0]= 1;
    for( int i = 0 ; i< nums.size(); i++){
        sum += nums[i];// we get the prefix sum
        // but catch is we need to check remainder present or not and remainder can be negative 
        int rem = sum%k;
        if( rem<0){
            rem = rem +k; // adding k makes it positive 
        }
        if( mp.find(rem)!= mp.end()){
            count += mp[rem];
        }
        mp[rem]++;
    }
    return count;
}
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        return helper( nums, k , mp);
    }
};