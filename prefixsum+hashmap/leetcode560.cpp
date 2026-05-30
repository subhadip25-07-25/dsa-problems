//https://leetcode.com/problems/subarray-sum-equals-k/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
          int prefixsum = 0 ;
          unordered_map<int,int>mp;
          mp[0]=1;
          int count = 0;
          for(int i = 0 ; i< nums.size(); i++){
             // mp[sum]++;  wrong fail for nuns [1] k  = 0
            prefixsum +=nums[i];
            int val = prefixsum-k;
            // it present in map 
            if(mp.find(val)!= mp.end()){
                count +=mp[val];
            }
            mp[prefixsum]++;// check first then insert 
          }
          return count;
    }
};
/*
Q1: Why do we update hashmap after checking?
✅ Interview Answer:

We update the hashmap after checking because we only want to count prefix sums that occurred before the current index.
If we insert the current prefix first, we might incorrectly count the current subarray itself, which is invalid.
So we first use the hashmap to find valid previous prefixes, then store the current prefix for future use.

💡 Short Version (if interviewer wants concise)

“To ensure we only use previous prefix sums and avoid counting the current index prematurely.”

🎯 Q2: What happens if we update hashmap before checking?
✅ Interview Answer:

If we update the hashmap before checking, the current prefix sum gets included in the map.
This can lead to incorrect counting, especially when sum - k == sum, such as when k = 0.
In that case, we end up counting the current prefix itself, resulting in overcounting invalid subarrays.

💡 Short Version

“It causes overcounting because the current prefix gets included and may match itself.”*/